$NetBSD: patch-source4_heimdal__build_roken.h,v 1.3 2022/03/07 21:40:38 thor Exp $

Substitute SYSCONFDIR in embedded Heimdal too.

--- source4/heimdal_build/roken.h.orig	2021-08-09 13:38:36.703383700 +0000
+++ source4/heimdal_build/roken.h
@@ -7,7 +7,7 @@
 #include "config.h"
 
 /* path to sysconf - should we force this to samba LIBDIR ? */
-#define SYSCONFDIR "/etc"
+#define SYSCONFDIR "/data/pkg/etc"
 
 #define rk_PATH_DELIM '/'
 
