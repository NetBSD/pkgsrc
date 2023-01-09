$NetBSD: patch-plugins_check_ide_smart.c,v 1.3 2023/01/09 00:28:41 sekiya Exp $

__u8 and __u16 are not defined in videoio.h in NetBSD 9.99.x.

--- plugins/check_ide_smart.c.orig	2019-12-05 06:53:08.000000000 +0900
+++ plugins/check_ide_smart.c	2023-01-09 08:53:27.415335124 +0900
@@ -56,11 +56,14 @@
 #include <sys/device.h>
 #include <sys/param.h>
 #include <sys/sysctl.h>
-#include <sys/videoio.h> /* for __u8 and friends */
 #include <sys/scsiio.h>
 #include <sys/ataio.h>
 #include <dev/ata/atareg.h>
 #include <dev/ic/wdcreg.h>
+#include <stdint.h>
+
+#define __u8 uint8_t
+#define __u16 uint16_t
 
 #define SMART_ENABLE WDSM_ENABLE_OPS
 #define SMART_DISABLE WDSM_DISABLE_OPS
