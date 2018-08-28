$NetBSD: patch-common_lsysf.c,v 1.1 2018/08/28 11:54:54 schmonz Exp $

--- common/lsysf.c.orig	2014-05-03 13:12:35.000000000 +0000
+++ common/lsysf.c
@@ -1,11 +1,5 @@
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
