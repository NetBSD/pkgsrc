$NetBSD: patch-plugins_check__ide__smart.c,v 1.1 2022/04/02 10:35:35 nia Exp $

__u8 and __u16 are not defined in videoio.h in NetBSD 9.99.x.

--- plugins/check_ide_smart.c.orig	2017-01-16 17:24:03.000000000 +0000
+++ plugins/check_ide_smart.c
@@ -56,11 +56,14 @@ void print_usage (void);
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
