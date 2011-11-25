$NetBSD: patch-src_html.cc,v 1.1 2011/11/25 21:38:09 joerg Exp $

--- src/html.cc.orig	2011-11-25 17:18:04.000000000 +0000
+++ src/html.cc
@@ -31,7 +31,7 @@
 #include <direct.h>
 #endif
 #include <errno.h>
-#include <iostream.h>
+#include <iostream>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
