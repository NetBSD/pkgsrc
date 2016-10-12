$NetBSD: patch-tools-for-build_grovel-headers.c,v 1.1 2016/10/12 11:35:48 asau Exp $

--- tools-for-build/grovel-headers.c.orig	2016-09-30 16:41:12.000000000 +0000
+++ tools-for-build/grovel-headers.c
@@ -18,6 +18,10 @@
  * more information.
  */
 
+#if defined(__NetBSD__)
+#define _KERNTYPES
+#endif
+
 #include "genesis/config.h"
 
 #include <stdio.h>
