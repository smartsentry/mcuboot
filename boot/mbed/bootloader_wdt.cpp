#include "mbed.h"
#include "bootloader_wdt.h"

Watchdog &wdt = mbed::Watchdog::get_instance();

class wdtstarter{
  public:
  wdtstarter(int time)
  {
    	wdt.start(time);
		__HAL_DBGMCU_FREEZE_IWDG();
  }
};
wdtstarter wdstart(10000);// Start watchdog with 10s timeout


extern "C" void bootloader_wdt_feed(void)
{
    wdt.kick();
}