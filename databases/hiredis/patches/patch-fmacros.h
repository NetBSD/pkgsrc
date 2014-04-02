$NetBSD: patch-fmacros.h,v 1.1 2014/04/02 17:25:45 wiedi Exp $
getaddrinfo visibility on NetBSD

--- fmacros.h.orig	2012-08-28 06:55:52.000000000 +0000
+++ fmacros.h
@@ -7,7 +7,7 @@
 
 #if defined(__sun__)
 #define _POSIX_C_SOURCE 200112L
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__NetBSD__)
 #define _XOPEN_SOURCE 600
 #else
 #define _XOPEN_SOURCE
