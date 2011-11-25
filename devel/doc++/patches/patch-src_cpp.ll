$NetBSD: patch-src_cpp.ll,v 1.1 2011/11/25 21:38:09 joerg Exp $

--- src/cpp.ll.orig	2011-11-25 17:18:33.000000000 +0000
+++ src/cpp.ll
@@ -26,7 +26,7 @@
 
 #include <assert.h>
 #include <ctype.h>
-#include <iostream.h>
+#include <iostream>
 #include <stdarg.h>
 #include <stdio.h>
 
