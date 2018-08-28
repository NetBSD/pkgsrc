$NetBSD: patch-common_memory.c,v 1.1 2018/08/28 11:54:54 schmonz Exp $

--- common/memory.c.orig	2014-05-03 13:12:35.000000000 +0000
+++ common/memory.c
@@ -1,10 +1,6 @@
 #include <string.h>
 #include <limits.h>
-#ifdef __APPLE__
-#include <malloc/malloc.h>
-#else
-#include <malloc.h>
-#endif
+#include <stdlib.h>
 
 #if (!defined(XFRACT) && !defined(WINFRACT))
 #include <io.h>
