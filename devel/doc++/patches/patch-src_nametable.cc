$NetBSD: patch-src_nametable.cc,v 1.1 2011/11/25 21:38:09 joerg Exp $

--- src/nametable.cc.orig	2011-11-25 17:21:36.000000000 +0000
+++ src/nametable.cc
@@ -22,7 +22,7 @@
 */
 
 #include <assert.h>
-#include <iostream.h>
+#include <iostream>
 #include <stdlib.h>
 #include <string.h>
 
