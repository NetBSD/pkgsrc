$NetBSD: patch-external_mysqlcppconn_config.h,v 1.2 2017/08/01 11:57:37 ryoon Exp $

--- external/mysqlcppconn/config.h.orig	2017-07-25 20:26:39.000000000 +0000
+++ external/mysqlcppconn/config.h
@@ -6,7 +6,7 @@
 #define HAVE_FUNCTION_STRTOL 1
 #define HAVE_FUNCTION_STRTOULL 1
 
-#if defined(MACOSX) || defined(__sun) || defined(LINUX) || defined (_MSC_VER)
+#if defined(MACOSX) || defined(__sun) || defined(LINUX) || defined (_MSC_VER) || defined(NETBSD)
     #define HAVE_STDINT_H
 #ifndef _MSC_VER
     #define HAVE_INTTYPES_H
