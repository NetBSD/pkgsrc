$NetBSD: patch-src_main.cpp,v 1.1 2014/09/11 16:59:16 jperkin Exp $

Avoid 'move' conflict.

--- src/main.cpp.orig	2014-08-17 11:03:08.000000000 +0000
+++ src/main.cpp
@@ -104,7 +104,7 @@ char exec_path[FILENAME_MAX];
 int main(int argc, char *argv[])
 {
   char mstring[10];
-  move hint;
+  my_move hint;
 
 #ifdef TEST_ASSERT
   assert(0);  // testing that asserts are off
