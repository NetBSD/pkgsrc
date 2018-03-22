$NetBSD: patch-src_grip.c,v 1.2 2018/03/22 13:29:11 triaxx Exp $

Add system dependent headers.

--- src/grip.c.orig	2018-01-31 15:06:36.000000000 +0000
+++ src/grip.c
@@ -26,6 +26,9 @@
 #include <stdio.h>
 #include <unistd.h>
 #include <sys/param.h>
+#if defined(__NetBSD__)
+#include <sys/wait.h>
+#endif
 #include <gdk/gdkx.h>
 #include <X11/Xlib.h>
 #include <time.h>
@@ -773,7 +776,7 @@ static void DoLoadConfig(GripInfo *ginfo
 
   *ginfo->version='\0';
 
-  strcpy(ginfo->cd_device,"/dev/cdrom");
+  strcpy(ginfo->cd_device,CD_DEVICE);
   *ginfo->force_scsi='\0';
 
   ginfo->local_mode=FALSE;
