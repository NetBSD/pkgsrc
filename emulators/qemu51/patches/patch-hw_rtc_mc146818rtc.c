$NetBSD: patch-hw_rtc_mc146818rtc.c,v 1.1 2021/02/20 22:55:19 ryoon Exp $

Ensure the periodic timer is started as soon as the device is realized,
and follow the real hardware's lead of updating the PF bit in REG_C even
if it's not going to result in raising an interrupt.

--- hw/rtc/mc146818rtc.c.orig	2020-10-01 00:56:55.574093880 +0000
+++ hw/rtc/mc146818rtc.c	2020-10-01 00:58:40.326479896 +0000
@@ -155,9 +155,15 @@ static uint32_t rtc_periodic_clock_ticks
 {
     int period_code;
 
+#if 0
+    /*
+     * Real hardware sets the PF bit rergardless if it actually
+     * raises an interrupt.
+     */
     if (!(s->cmos_data[RTC_REG_B] & REG_B_PIE)) {
         return 0;
      }
+#endif
 
     period_code = s->cmos_data[RTC_REG_A] & 0x0f;
 
@@ -944,6 +950,7 @@ static void rtc_realizefn(DeviceState *d
     }
 
     s->periodic_timer = timer_new_ns(rtc_clock, rtc_periodic_timer, s);
+    periodic_timer_update(s, qemu_clock_get_ns(rtc_clock), 0, true);
     s->update_timer = timer_new_ns(rtc_clock, rtc_update_timer, s);
     check_update_timer(s);
 
