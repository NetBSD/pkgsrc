$NetBSD: patch-src_lib_FHParser.cpp,v 1.1 2015/06/27 18:41:40 joerg Exp $

--- src/lib/FHParser.cpp.orig	2015-06-27 14:09:14.000000000 +0000
+++ src/lib/FHParser.cpp
@@ -25,7 +25,14 @@
 namespace
 {
 
+#ifdef __clang__
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wdeprecated-register"
+#endif
 #include "tokenhash.h"
+#ifdef __clang__
+#pragma GCC diagnostic pop
+#endif
 
 static int getTokenId(const char *name)
 {
