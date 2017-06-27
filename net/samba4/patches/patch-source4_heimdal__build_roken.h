$NetBSD: patch-source4_heimdal__build_roken.h,v 1.1 2017/06/27 13:37:16 fhajny Exp $

Substitute SYSCONFDIR in embedded Heimdal too.

--- source4/heimdal_build/roken.h.orig	2017-01-11 07:55:15.000000000 +0000
+++ source4/heimdal_build/roken.h
@@ -10,7 +10,7 @@
 #define HEIM_WEAK_CRYPTO 1
 
 /* path to sysconf - should we force this to samba LIBDIR ? */
-#define SYSCONFDIR "/etc"
+#define SYSCONFDIR "@PKG_SYSCONFBASE@"
 
 #define rk_PATH_DELIM '/'
 
