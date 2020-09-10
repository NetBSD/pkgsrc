$NetBSD: patch-wmbattery.c,v 1.1 2020/09/10 11:26:01 nia Exp $

Adds support for envsys (see ../files/envsys.c).

--- wmbattery.c.orig	2020-09-01 05:47:33.306716070 +0000
+++ wmbattery.c
@@ -49,6 +49,9 @@
 #ifdef UPOWER
 #include "upower.h"
 #endif
+#ifdef ENVSYS
+#include "envsys.h"
+#endif
 
 Pixmap images[NUM_IMAGES];
 Window root, iconwin, win;
@@ -78,6 +81,9 @@ int use_simplehal = 0;
 #ifdef UPOWER
 int use_upower = 0;
 #endif
+#ifdef ENVSYS
+int use_envsys = 0;
+#endif
 int use_sonypi = 0;
 int use_acpi = 0;
 int delay = 0;
@@ -719,6 +725,12 @@ void alarmhandler(int sig)
 		if (acpi_read(battnum, &cur_info) != 0)
 			error("Cannot read ACPI information.");
 	}
+#ifdef ENVSYS
+    else if (use_envsys) {
+        if (envsys_read(battnum, &cur_info) != 0)
+            error("Cannot read envsys information.");
+    }
+#endif
 #ifdef HAL
 	else if (use_simplehal) {
 		if (simplehal_read(battnum, &cur_info) != 0)
@@ -784,8 +796,18 @@ int main(int argc, char *argv[])
 {
 	make_window(parse_commandline(argc, argv), argc, argv);
 
+#ifdef ENVSYS
+    /* Check for envsys support. */
+    if (envsys_supported()) {
+        use_envsys = 1;
+        if (!delay)
+            delay = 2;
+    }
 	/*  Check for APM support (returns 0 on success). */
+    else if (apm_exists() == 0) {
+#else
 	if (apm_exists() == 0) {
+#endif
 		if (!delay)
 			delay = 1;
 	}
@@ -816,7 +838,7 @@ int main(int argc, char *argv[])
 		if (!delay)
 			delay = 1;
 	} else {
-		error("No APM, ACPI, UPOWER, HAL or SPIC support detected.");
+		error("No envsys, APM, ACPI, UPOWER, HAL or SPIC support detected.");
 	}
 
 	load_images();
