$NetBSD: patch-ext_aemu__postoffice_client_sock__impl.h,v 1.1 2026/03/11 08:13:43 adam Exp $

Fix build on NetBSD.

--- ext/aemu_postoffice/client/sock_impl.h.orig	2026-03-11 07:06:03.419915041 +0000
+++ ext/aemu_postoffice/client/sock_impl.h
@@ -3,7 +3,7 @@
 
 #include <stdbool.h>
 
-#if defined(__unix) || defined(__APPLE__) || defined(__PSP__)
+#if defined(__unix) || defined(__APPLE__) || defined(__PSP__) || defined(__NetBSD__)
 #include <netinet/in.h>
 #endif
 
