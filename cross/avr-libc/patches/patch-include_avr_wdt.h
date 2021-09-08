$NetBSD: patch-include_avr_wdt.h,v 1.1 2021/09/08 12:20:35 micha Exp $

Fix comments for ATmega324PA.

--- include/avr/wdt.h.orig	2016-02-07 22:59:49.000000000 +0000
+++ include/avr/wdt.h
@@ -549,7 +549,7 @@ void wdt_disable (void)
     ATtiny261, ATtiny461, ATtiny861, 
     ATmega48, ATmega88, ATmega168,
     ATmega48P, ATmega88P, ATmega168P, ATmega328P,
-    ATmega164P, ATmega324P, ATmega644P, ATmega644,
+    ATmega164P, ATmega324P, ATmega324PA, ATmega644P, ATmega644,
     ATmega640, ATmega1280, ATmega1281, ATmega2560, ATmega2561,
     ATmega8HVA, ATmega16HVA, ATmega32HVB,
     ATmega406, ATmega1284P,
@@ -570,7 +570,7 @@ void wdt_disable (void)
     ATtiny261, ATtiny461, ATtiny861, 
     ATmega48, ATmega48A, ATmega48PA, ATmega88, ATmega168,
     ATmega48P, ATmega88P, ATmega168P, ATmega328P,
-    ATmega164P, ATmega324P, ATmega644P, ATmega644,
+    ATmega164P, ATmega324P, ATmega324PA, ATmega644P, ATmega644,
     ATmega640, ATmega1280, ATmega1281, ATmega2560, ATmega2561,
     ATmega8HVA, ATmega16HVA, ATmega32HVB,
     ATmega406, ATmega1284P,
