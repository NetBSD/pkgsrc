$NetBSD: patch-src_ordinal.h,v 1.1 2012/12/20 21:47:31 joerg Exp $

--- src/ordinal.h.orig	2012-12-20 18:37:13.000000000 +0000
+++ src/ordinal.h
@@ -1,3 +1,5 @@
+#ifndef ORDINAL_H
+#define ORDINAL_H
 #include <stdlib.h>
 #include <iostream>
 #include <gmpxx.h>
@@ -255,7 +257,4 @@ public:
     extern bool interactiveMode ;
 }
 
-
-
-
-
+#endif
