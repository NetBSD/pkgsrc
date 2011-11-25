$NetBSD: patch-src_java.ll,v 1.1 2011/11/25 21:38:09 joerg Exp $

--- src/java.ll.orig	2011-11-25 17:21:13.000000000 +0000
+++ src/java.ll
@@ -26,7 +26,7 @@
 
 #include <assert.h>
 #include <ctype.h>
-#include <iostream.h>
+#include <iostream>
 #include <stdio.h>
 
 #include "doc.h"
