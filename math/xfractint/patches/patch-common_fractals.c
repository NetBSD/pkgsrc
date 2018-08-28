$NetBSD: patch-common_fractals.c,v 1.1 2018/08/28 11:54:54 schmonz Exp $

--- common/fractals.c.orig	2015-01-19 18:35:16.000000000 +0000
+++ common/fractals.c
@@ -39,13 +39,7 @@ an appropriate setup, per_image, per_pix
 
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
