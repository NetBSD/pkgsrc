$NetBSD: patch-third__party_heimdal__build_roken.h,v 1.1 2022/07/21 09:35:19 adam Exp $

Substitute SYSCONFDIR in embedded Heimdal too.

--- third_party/heimdal_build/roken.h.orig	2021-08-09 13:38:36.703383700 +0000
+++ third_party/heimdal_build/roken.h
@@ -7,7 +7,7 @@
 #include "config.h"
 
 /* path to sysconf - should we force this to samba LIBDIR ? */
-#define SYSCONFDIR "/etc"
+#define SYSCONFDIR "@PKG_SYSCONFBASE@"
 
 #define rk_PATH_DELIM '/'
 
