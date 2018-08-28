$NetBSD: patch-common_biginit.c,v 1.1 2018/08/28 11:54:54 schmonz Exp $

--- common/biginit.c.orig	2014-05-03 13:12:35.000000000 +0000
+++ common/biginit.c
@@ -7,11 +7,7 @@ is in the allocations of memory for the 
 */
 
 #include <string.h>
-#ifdef __APPLE__
-#include <malloc/malloc.h>
-#else
-#include <malloc.h>
-#endif
+#include <stdlib.h>
   /* see Fractint.c for a description of the "include"  hierarchy */
 #include "port.h"
 #include "prototyp.h"
