$NetBSD: patch-cpp_cpp.c,v 1.1 2025/12/17 10:55:53 prlw1 Exp $

Fix build: type of 'ch' defaults to 'int'

--- cpp/cpp.c.orig	2014-03-14 04:33:19.000000000 +0000
+++ cpp/cpp.c
@@ -545,7 +545,7 @@ chget()
 }
 
 static void 
-unchget(ch)
+unchget(int ch)
 {
 #if CPP_DEBUG
    fprintf(stderr, "\b", ch);
