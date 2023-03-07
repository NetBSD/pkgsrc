$NetBSD: patch-include_mysql_service__encryption.h,v 1.1 2023/03/07 10:28:02 jperkin Exp $

SunOS always needs alloca.h.

--- include/mysql/service_encryption.h.orig	2022-11-02 12:37:17.000000000 +0000
+++ include/mysql/service_encryption.h
@@ -36,7 +36,7 @@ extern "C" {
 #endif
 #else
 #include <stdlib.h>
-#ifdef HAVE_ALLOCA_H
+#if defined(HAVE_ALLOCA_H) || defined(__sun)
 #include <alloca.h>
 #endif
 #endif
