$NetBSD: patch-common_miscres.c,v 1.1 2018/08/28 11:54:54 schmonz Exp $

--- common/miscres.c.orig	2014-05-03 13:12:35.000000000 +0000
+++ common/miscres.c
@@ -5,11 +5,7 @@
 #include <string.h>
 #include <ctype.h>
 #include <time.h>
-#ifdef __APPLE__
-#include <malloc/malloc.h>
-#else
-#include <malloc.h>
-#endif
+#include <stdlib.h>
 
 #ifndef XFRACT
 #include <io.h>
