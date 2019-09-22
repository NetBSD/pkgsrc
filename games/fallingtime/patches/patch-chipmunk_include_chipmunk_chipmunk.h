$NetBSD: patch-chipmunk_include_chipmunk_chipmunk.h,v 1.1 2019/09/22 12:10:45 nia Exp $

Support alloca in stdlib.

--- chipmunk/include/chipmunk/chipmunk.h.orig	2015-10-21 09:55:38.000000000 +0000
+++ chipmunk/include/chipmunk/chipmunk.h
@@ -32,6 +32,9 @@
 #ifdef WIN32
 	// For alloca().
 	#include <malloc.h>
+#endif
+#if defined(__NetBSD__) || defined(__FreeBSD__)
+	#include <stdlib.h>
 #else
 	#include <alloca.h>
 #endif
