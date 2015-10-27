$NetBSD: patch-res_pjproject_third__party_portaudio_src_hostapi_oss_pa__unix__oss.c,v 1.1 2015/10/27 08:49:01 jnemeth Exp $

--- res/pjproject/third_party/portaudio/src/hostapi/oss/pa_unix_oss.c.orig	2015-10-09 22:23:39.000000000 +0000
+++ res/pjproject/third_party/portaudio/src/hostapi/oss/pa_unix_oss.c
@@ -59,7 +59,7 @@
 #include <errno.h>
 #include <sys/types.h>
 #include <sys/stat.h>
-#include <sys/poll.h>
+#include <poll.h>
 #include <limits.h>
 #include <semaphore.h>
 
