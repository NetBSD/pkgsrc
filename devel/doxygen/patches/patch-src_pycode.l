$NetBSD: patch-src_pycode.l,v 1.1 2016/01/15 18:04:06 tron Exp $

Remove bogus flex version check that breaks the build with flex 2.6.0.

--- src/pycode.l.orig	2015-01-03 22:38:57.000000000 +0000
+++ src/pycode.l	2016-01-15 14:05:15.828019703 +0000
@@ -1503,7 +1503,5 @@
 extern "C" { // some bogus code to keep the compiler happy
   void pycodeYYdummy() { yy_flex_realloc(0,0); } 
 }
-#elif YY_FLEX_SUBMINOR_VERSION<33
-#error "You seem to be using a version of flex newer than 2.5.4. These are currently incompatible with 2.5.4, and do NOT work with doxygen! Please use version 2.5.4 or expect things to be parsed wrongly! A bug report has been submitted (#732132)."
 #endif
 
