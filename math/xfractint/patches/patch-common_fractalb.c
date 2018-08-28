$NetBSD: patch-common_fractalb.c,v 1.1 2018/08/28 11:54:54 schmonz Exp $

--- common/fractalb.c.orig	2014-05-03 13:12:35.000000000 +0000
+++ common/fractalb.c
@@ -8,13 +8,7 @@ fractal routines.
 
 #include <limits.h>
 #include <string.h>
-#ifdef __TURBOC__
-#include <alloc.h>
-#elif defined(__APPLE__)
-#include <malloc/malloc.h>
-#elif !defined(__386BSD__)
-#include <malloc.h>
-#endif
+#include <stdlib.h>
   /* see Fractint.c for a description of the "include"  hierarchy */
 #include "port.h"
 #include "prototyp.h"
