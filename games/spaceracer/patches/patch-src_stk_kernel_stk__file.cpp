$NetBSD: patch-src_stk_kernel_stk__file.cpp,v 1.1 2026/01/03 10:52:03 wiz Exp $

ISO C++17 does not allow dynamic exception specifications.

--- src/stk/kernel/stk_file.cpp.orig	2026-01-03 10:49:25.556179740 +0000
+++ src/stk/kernel/stk_file.cpp
@@ -4,7 +4,7 @@
 #include <string.h>
 #include "stk_file.h"
 
-Stk_File::Stk_File(char *filename) throw (xFileError)
+Stk_File::Stk_File(char *filename)
 {
         // init the file descriptor
     fd=0;
