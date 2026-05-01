$NetBSD: patch-cmake_config.h.cmake,v 1.1 2026/05/01 19:43:30 vins Exp $

Set definition for getprotobyname() check.

--- cmake/config.h.cmake.orig	2024-12-14 08:03:11.000000000 +0000
+++ cmake/config.h.cmake
@@ -33,6 +33,9 @@
 /* Define to 1 if you have the <netdb.h> header file. */
 #cmakedefine HAVE_NETDB_H
 
+/* Define to 1 if <netdb.h> has the getprotobyname() function. */
+#cmakedefine HAVE_GETPROTOBYNAME
+
 /* Define to 1 if you have the <netinet/in.h> header file. */
 #cmakedefine HAVE_NETINET_IN_H
 
