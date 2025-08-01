$NetBSD: patch-src_devices_machine_macseconds.cpp,v 1.1 2025/08/01 18:31:11 wiz Exp $

macseconds: correct include order
https://github.com/mamedev/mame/commit/468dfe69a4ba94411359252fca284b69601d56d7

--- src/devices/machine/macseconds.cpp.orig	2025-07-30 22:06:29.000000000 +0000
+++ src/devices/machine/macseconds.cpp
@@ -8,11 +8,11 @@
     (seconds since 1/1/1904 at midnight).
 */
 
-#include "dirtc.h"
-
 #include "emu.h"
 #include "macseconds.h"
 
+#include "dirtc.h"
+
 macseconds_interface::macseconds_interface()
 {
 	// Get the current time to get the DST flag and compute the offset from GMT
@@ -35,8 +35,7 @@ u32 macseconds_interface::get_local_seco
 {
 	const system_time::full_time &time = systime.local_time;
 
-	return get_seconds(time.year - 2000, time.month + 1, time.mday, time.weekday + 1, time.hour,
-							  time.minute, time.second);
+	return get_seconds(time.year - 2000, time.month + 1, time.mday, time.weekday + 1, time.hour, time.minute, time.second);
 }
 
 u32 macseconds_interface::get_seconds(int year, int month, int day, int day_of_week, int hour, int minute, int second)
