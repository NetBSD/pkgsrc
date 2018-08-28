$NetBSD: patch-common_prompts2.c,v 1.1 2018/08/28 11:54:54 schmonz Exp $

--- common/prompts2.c.orig	2015-08-08 13:22:41.000000000 +0000
+++ common/prompts2.c
@@ -22,13 +22,7 @@
 #endif
 
 #endif
-#ifdef __TURBOC__
-#include <alloc.h>
-#elif defined(__APPLE__)
-#include <malloc/malloc.h>
-#elif !defined(__386BSD__)
-#include <malloc.h>
-#endif
+#include <stdlib.h>
 
 #ifdef XFRACT
 #include <fcntl.h>
