$NetBSD: patch-hw_rtc_mc146818rtc.c,v 1.2 2026/11/20 16:43:05 thorpej Exp $

Ensure the periodic timer is started as soon as the device is realized,
and follow the real hardware's lead of updating the PF bit in REG_C even
if it's not going to result in raising an interrupt.

--- hw/rtc/mc146818rtc.c.orig	2026-10-28 19:57:39.000000000 +0000
+++ hw/rtc/mc146818rtc.c	2026-11-20 13:49:44.592550959 +0000
@@ -132,10 +132,6 @@ static uint32_t rtc_periodic_clock_ticks
 {
     int period_code;
 
-    if (!(s->cmos_data[RTC_REG_B] & REG_B_PIE)) {
-        return 0;
-     }
-
     period_code = s->cmos_data[RTC_REG_A] & 0x0f;
 
     return periodic_period_to_clock(period_code);
@@ -160,6 +156,12 @@ static void periodic_timer_update(MC1468
         return;
     }
 
+    if (!(s->cmos_data[RTC_REG_B] & REG_B_PIE) &&
+        (s->cmos_data[RTC_REG_C] & REG_C_PF)) {
+        timer_del(s->periodic_timer);
+        return;
+    }
+
     /* compute 32 khz clock */
     cur_clock =
         muldiv64(current_time, RTC_CLOCK_RATE, NANOSECONDS_PER_SECOND);
@@ -192,7 +194,8 @@ static void periodic_timer_update(MC1468
      *    to a shorter period, scale up the missing ticks since the
      *    OS handler will treat past delayed ticks as shorter.
      */
-    if (s->lost_tick_policy == LOST_TICK_POLICY_SLEW) {
+    if (s->lost_tick_policy == LOST_TICK_POLICY_SLEW &&
+        (s->cmos_data[RTC_REG_B] & REG_B_PIE)) {
         uint32_t old_irq_coalesced = s->irq_coalesced;
 
         lost_clock += old_irq_coalesced * old_period;
@@ -239,6 +242,8 @@ static void rtc_periodic_timer(void *opa
             }
         } else
             qemu_irq_raise(s->irq);
+    } else {
+        timer_del(s->periodic_timer);
     }
 }
 
@@ -700,6 +705,10 @@ static uint64_t cmos_ioport_read(void *o
             if (ret & (REG_C_UF | REG_C_AF)) {
                 check_update_timer(s);
             }
+	    if ((ret & REG_C_PF) && !(s->cmos_data[RTC_REG_B] & REG_B_PIE)) {
+                periodic_timer_update(s, qemu_clock_get_ns(rtc_clock),
+                                      s->period, false);
+            }
 
             if(s->irq_coalesced &&
                     (s->cmos_data[RTC_REG_B] & REG_B_PIE) &&
