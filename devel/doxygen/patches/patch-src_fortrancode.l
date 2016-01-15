$NetBSD: patch-src_fortrancode.l,v 1.1 2016/01/15 18:04:06 tron Exp $

Remove bogus flex version check that breaks the build with flex 2.6.0.

--- src/fortrancode.l.orig	2015-01-03 22:38:57.000000000 +0000
+++ src/fortrancode.l	2016-01-15 14:05:04.598856168 +0000
@@ -1289,11 +1289,5 @@
 extern "C" { // some bogus code to keep the compiler happy
   void fortrancodeYYdummy() { yy_flex_realloc(0,0); } 
 }
-#elif YY_FLEX_SUBMINOR_VERSION<33
-#error "You seem to be using a version of flex newer than 2.5.4 but older than 2.5.33. These versions do NOT work with doxygen! Please use version <=2.5.4 or >=2.5.33 or expect things to be parsed wrongly!"
-#else
-extern "C" { // some bogus code to keep the compiler happy
-  void fortrancodeYYdummy() { yy_top_state(); } 
-}
 #endif
 
