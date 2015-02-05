$NetBSD: patch-src_file_mmc__device__linux.c,v 1.1 2015/02/05 17:34:09 joerg Exp $

--- src/file/mmc_device_linux.c.orig	2015-02-04 13:50:55.000000000 +0000
+++ src/file/mmc_device_linux.c
@@ -32,6 +32,7 @@
 #include "util/strutl.h"
 
 #include <stdlib.h>
+#include <stdio.h>
 #include <string.h>
 #include <unistd.h>
 #include <fcntl.h>
@@ -180,8 +181,8 @@ MMCDEV *device_open(const char *path)
         } else {
             BD_DEBUG(DBG_MMC | DBG_CRIT, "Error opening /proc/mounts\n");
         }
-#endif
     }
+#endif
 
     if (fd >= 0) {
         dev = calloc(1, sizeof(MMCDEV));
