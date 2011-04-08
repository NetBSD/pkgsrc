$NetBSD: patch-lib_fs.h,v 1.1 2011/04/08 22:48:04 wiz Exp $

Fix build on DragonFly (missing MAXNAMLEN macro), from upstream.

--- lib/fs.h.orig      2010-11-08 11:46:13 +0000
+++ lib/fs.h
@@ -44,6 +44,12 @@
 #   define S_ISNAM(x) 0
 #endif
 
+/* DragonFlyBSD doesn't provide MAXNAMLEN macro */
+#ifndef MAXNAMLEN
+#   define MAXNAMLEN NAME_MAX
+#endif
+
+#define MC_MAXFILENAMELEN MAXNAMLEN
 
 #ifndef MAXPATHLEN
 #   define MC_MAXPATHLEN 4096
