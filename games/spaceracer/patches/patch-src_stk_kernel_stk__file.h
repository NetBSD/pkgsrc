$NetBSD: patch-src_stk_kernel_stk__file.h,v 1.1 2026/01/03 10:52:03 wiz Exp $

ISO C++17 does not allow dynamic exception specifications.

--- src/stk/kernel/stk_file.h.orig	2026-01-03 10:47:50.849521600 +0000
+++ src/stk/kernel/stk_file.h
@@ -17,7 +17,7 @@ class Stk_File
 {
 public:
         /// Constructor
-    Stk_File(char *filename) throw (xFileError);
+    Stk_File(char *filename);
         /// Destructor
     virtual ~Stk_File();
 
