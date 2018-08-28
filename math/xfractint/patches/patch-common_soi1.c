$NetBSD: patch-common_soi1.c,v 1.1 2018/08/28 11:54:54 schmonz Exp $

--- common/soi1.c.orig	2014-05-03 13:12:35.000000000 +0000
+++ common/soi1.c
@@ -13,11 +13,7 @@
  */
 #include <time.h>
 #include <string.h>
-#ifdef __APPLE__
-#include <malloc/malloc.h>
-#else
-#include <malloc.h>
-#endif
+#include <stdlib.h>
 #include "port.h"
 #include "prototyp.h"
 
