$NetBSD: patch-panel-plugin_battery.c,v 1.4 2019/01/18 17:53:27 youri Exp $

Fix for NetBSD.

--- panel-plugin/battery.c.orig	2019-01-18 17:56:56.433182652 +0000
+++ panel-plugin/battery.c
@@ -26,13 +26,32 @@
 #include <config.h>
 #endif
 
-#if (defined(__OpenBSD__) || defined(__NetBSD__))
-#include <sys/param.h>
-#include <sys/ioctl.h>
-#include <machine/apmvar.h>
-#define APMDEVICE "/dev/apm"
+#if defined(__NetBSD__)
+	#include <sys/param.h>
+	#include <sys/ioctl.h>
+	#include <dev/apm/apmbios.h>
+	#include <dev/apm/apmio.h>
+	#define APMDEVICE "dev/apm"
+	#define _ACPI_APM_BATT_UNKNOWN 0xffff /* from sys/dev/apci/acpi_apm.c */
+#elif (defined(__FreeBSD__) || defined(__FreeBSD_kernel__)) && \
+				(defined(i386) || defined(__i386__))
+	#include <machine/apm_bios.h>
+#elif defined(__OpenBSD__)
+	#include <sys/param.h>
+	#include <sys/ioctl.h>
+	#if defined(__sparc64__)
+		#include <sparc/apmvar.h>
+	#elif defined(__x86_64__)
+		#include <dev/apm/apmbios.h>
+		#include <dev/apm/apmio.h>
+	#else
+		#include <machine/apmvar.h>
+	#endif
+	#define APMDEVICE "/dev/apm"
+	#define _ACPI_APM_BATT_UNKNOWN 0xffff /* from sys/dev/apci/acpi_apm.c */
 #endif
 
+
 #include <sys/stat.h>
 #include <sys/types.h>
 #include <fcntl.h>
