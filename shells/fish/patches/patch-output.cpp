$NetBSD: patch-output.cpp,v 1.1 2015/03/18 15:03:43 joerg Exp $

--- output.cpp.orig	2015-03-17 21:47:33.000000000 +0000
+++ output.cpp
@@ -151,7 +151,7 @@ unsigned char index_for_color(rgb_color_
 }
 
 
-static bool write_color(char *todo, unsigned char idx, bool is_fg)
+static bool write_color(const char *todo, unsigned char idx, bool is_fg)
 {
     bool result = false;
     if (idx < 16 || term256_support_is_native())
@@ -418,7 +418,7 @@ int writeb(tputs_arg_t b)
     return 0;
 }
 
-int writembs_internal(char *str)
+int writembs_internal(const char *str)
 {
     CHECK(str, 1);
 
