$NetBSD: patch-common_uposixdefs.h,v 1.1 2012/05/08 16:10:39 hans Exp $

--- common/uposixdefs.h.orig	2012-04-05 22:46:18.000000000 +0200
+++ common/uposixdefs.h	2012-05-08 15:28:20.516380420 +0200
@@ -52,9 +52,11 @@
  *
  * z/OS needs this definition for timeval and to get usleep.
  */
+#ifndef __sun
 #if !defined(_XOPEN_SOURCE_EXTENDED)
 #   define _XOPEN_SOURCE_EXTENDED 1
 #endif
+#endif
 
 /*
  * There is an issue with turning on _XOPEN_SOURCE_EXTENDED on certain platforms.
