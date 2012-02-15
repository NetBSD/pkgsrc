$NetBSD: patch-src_s__inter.c,v 1.1 2012/02/15 22:36:39 hans Exp $

--- src/s_inter.c.orig	2011-03-19 23:22:27.000000000 +0100
+++ src/s_inter.c	2012-01-02 14:13:33.293463566 +0100
@@ -52,6 +52,10 @@ typedef int socklen_t;
 #include <stdlib.h>
 #endif
 
+#ifdef __sun
+typedef void (*sig_t)();
+#endif
+
 #define DEBUG_MESSUP 1      /* messages up from pd to pd-gui */
 #define DEBUG_MESSDOWN 2    /* messages down from pd-gui to pd */
 
