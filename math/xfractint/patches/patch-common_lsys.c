$NetBSD: patch-common_lsys.c,v 1.1 2018/08/28 11:54:54 schmonz Exp $

--- common/lsys.c.orig	2015-01-19 18:35:16.000000000 +0000
+++ common/lsys.c
@@ -1,12 +1,6 @@
 
 #include <string.h>
-#ifdef __TURBOC__
-#include <alloc.h>
-#elif defined(__APPLE__)
-#include <malloc/malloc.h>
-#else
-#include <malloc.h>
-#endif
+#include <stdlib.h>
 
   /* see Fractint.c for a description of the "include"  hierarchy */
 #include "port.h"
