$NetBSD: patch-src-config-param.nbsd60.h,v 1.1 2012/08/30 17:37:55 jakllsch Exp $

--- src/config/param.nbsd60.h.orig	2012-04-22 23:40:23.000000000 -0400
+++ src/config/param.nbsd60.h	2012-04-28 19:34:45.000000000 -0400
@@ -34,6 +34,7 @@
 #define AFS_NBSD30_ENV 1
 #define AFS_NBSD40_ENV 1
 #define AFS_NBSD50_ENV 1
+#define AFS_NBSD60_ENV 1
 #undef  AFS_NONFSTRANS
 #define AFS_NONFSTRANS 1
 
