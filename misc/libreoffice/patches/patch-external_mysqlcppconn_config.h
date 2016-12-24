$NetBSD: patch-external_mysqlcppconn_config.h,v 1.1 2016/12/24 21:45:03 ryoon Exp $

--- external/mysqlcppconn/config.h.orig	2016-12-13 16:57:41.000000000 +0000
+++ external/mysqlcppconn/config.h
@@ -6,7 +6,7 @@
 #define HAVE_FUNCTION_STRTOL 1
 #define HAVE_FUNCTION_STRTOULL 1
 
-#if defined(MACOSX) || defined(SOLARIS) || defined(LINUX) || (defined _MSC_VER && _MSC_VER >= 1600)
+#if defined(MACOSX) || defined(SOLARIS) || defined(LINUX) || (defined _MSC_VER && _MSC_VER >= 1600) || defined(NETBSD)
     #define HAVE_STDINT_H
 #ifndef _MSC_VER
     #define HAVE_INTTYPES_H
