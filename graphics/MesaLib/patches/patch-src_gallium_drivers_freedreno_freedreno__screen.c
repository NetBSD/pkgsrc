$NetBSD: patch-src_gallium_drivers_freedreno_freedreno__screen.c,v 1.1 2022/03/13 15:52:50 tnn Exp $

sysinfo(2) is for Linux only

--- src/gallium/drivers/freedreno/freedreno_screen.c.orig	2021-12-01 19:04:14.000000000 +0000
+++ src/gallium/drivers/freedreno/freedreno_screen.c
@@ -43,7 +43,9 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include "drm-uapi/drm_fourcc.h"
+#if !defined(__NetBSD__)
 #include <sys/sysinfo.h>
+#endif
 
 #include "freedreno_fence.h"
 #include "freedreno_perfetto.h"
@@ -1020,9 +1022,13 @@ fd_screen_create(struct fd_device *dev, 
    driParseConfigFiles(config->options, config->options_info, 0, "msm",
                        NULL, fd_dev_name(screen->dev_id), NULL, 0, NULL, 0);
 
+#if defined(__NetBSD__)
+   screen->ram_size = 512 * 1024 * 1024; /* XXX should use sysctl hw.physmem64 here */
+#else
    struct sysinfo si;
    sysinfo(&si);
    screen->ram_size = si.totalram;
+#endif
 
    DBG("Pipe Info:");
    DBG(" GPU-id:          %s", fd_dev_name(screen->dev_id));
