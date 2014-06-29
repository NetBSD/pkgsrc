$NetBSD: patch-vfu_vfuopt.h,v 1.1 2014/06/29 19:43:54 dholland Exp $

Sprinkle const to make more modern C++ compilers happier.

--- vfu/vfuopt.h~	2002-04-26 07:24:21.000000000 +0000
+++ vfu/vfuopt.h
@@ -15,9 +15,9 @@
 #include "see.h"
 #include "vfuuti.h"
 
-  extern char *NOYES[];
-  extern char *FTIMETYPE[];
-  extern char *TAGMARKS[];
+  extern const char *const NOYES[];
+  extern const char *const FTIMETYPE[];
+  extern const char *const TAGMARKS[];
 
   struct Options {
     int sort_order; 
