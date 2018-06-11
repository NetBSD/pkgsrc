$NetBSD: patch-src_wtmp-helper.c,v 1.1 2018/06/11 23:55:50 youri Exp $

NetBSD call WTMPX_FILENAME _PATH_WTMPX.

--- src/wtmp-helper.c.orig	2016-01-27 18:38:21.000000000 +0000
+++ src/wtmp-helper.c
@@ -27,6 +27,10 @@
 
 #ifdef HAVE_UTMPX_H
 
+#ifdef __NetBSD__
+#define WTMPX_FILENAME	_PATH_WTMPX
+#endif
+
 #include <utmpx.h>
 
 typedef struct {
