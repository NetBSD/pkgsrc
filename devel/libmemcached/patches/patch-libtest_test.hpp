$NetBSD: patch-libtest_test.hpp,v 1.1 2013/09/12 14:20:56 fhajny Exp $

cstdarg needed for va_start.
--- libtest/test.hpp.orig	2013-04-03 04:22:00.000000000 +0000
+++ libtest/test.hpp
@@ -57,6 +57,7 @@
 
 #define LIBYATL_DEFAULT_PARAM __FILE__, __LINE__, __PRETTY_FUNCTION__
 
+#include <cstdarg>
 #include <cstdio>
 #include <cstdlib>
 #include <arpa/inet.h>
