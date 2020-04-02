$NetBSD: patch-source4_heimdal__build_roken.h,v 1.2 2020/04/02 11:21:42 adam Exp $

Substitute SYSCONFDIR in embedded Heimdal too.

--- source4/heimdal_build/roken.h.orig	2020-01-31 10:25:36.000000000 +0000
+++ source4/heimdal_build/roken.h
@@ -7,7 +7,7 @@
 #include "config.h"
 
 /* path to sysconf - should we force this to samba LIBDIR ? */
-#define SYSCONFDIR "/etc"
+#define SYSCONFDIR "@PKG_SYSCONFBASE@"
 
 #define rk_PATH_DELIM '/'
 
