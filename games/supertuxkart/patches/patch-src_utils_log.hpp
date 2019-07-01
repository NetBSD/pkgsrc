$NetBSD: patch-src_utils_log.hpp,v 1.2 2019/07/01 10:56:20 nia Exp $

Fix gnuc_va_list problem

--- src/utils/log.hpp.orig	2019-04-20 16:40:13.000000000 +0000
+++ src/utils/log.hpp
@@ -31,6 +31,7 @@
 
 
 #ifdef __GNUC__
+typedef __builtin_va_list __gnuc_va_list;
 #  define VALIST __gnuc_va_list
 #else
 #  define VALIST char*
