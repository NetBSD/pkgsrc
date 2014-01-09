$NetBSD: patch-src_utils_log.hpp,v 1.1 2014/01/09 12:17:32 ryoon Exp $

--- src/utils/log.hpp.orig	2013-11-15 11:43:21.000000000 +0000
+++ src/utils/log.hpp
@@ -26,7 +26,8 @@
 #include <stdlib.h>
 #include <string>
 
-#ifdef __GNUC__
+#if defined(__GNUC__ )
+typedef __builtin_va_list __gnuc_va_list;
 #  define VALIST __gnuc_va_list
 #else
 #  define VALIST char*
