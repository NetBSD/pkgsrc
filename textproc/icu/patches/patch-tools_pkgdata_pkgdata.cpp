$NetBSD: patch-tools_pkgdata_pkgdata.cpp,v 1.1 2015/10/26 09:48:14 jperkin Exp $

Fix preprocessor logic bug.

--- tools/pkgdata/pkgdata.cpp.orig	2015-10-08 03:54:02.000000000 +0000
+++ tools/pkgdata/pkgdata.cpp
@@ -24,7 +24,7 @@
 #include "putilimp.h"
 
 #if U_HAVE_POPEN
-#if (U_PF_MINGW <= U_PLATFORM || U_PLATFORM <= U_PF_CYGWIN) && defined(__STRICT_ANSI__)
+#if (U_PLATFORM <= U_PF_MINGW || U_PLATFORM <= U_PF_CYGWIN) && defined(__STRICT_ANSI__)
 /* popen/pclose aren't defined in strict ANSI on Cygwin and MinGW */
 #undef __STRICT_ANSI__
 #endif
