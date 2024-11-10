$NetBSD: patch-TSRM_TSRM.h,v 1.1 2024/11/10 22:09:50 prlw1 Exp $

Backport of

https://github.com/php/php-src/commit/2d6bd1644d104fe934a5117d232d3f50ffe9ff28

to fix

Cannot load lib/httpd/mod_php8.so into server: /usr/pkg/lib/httpd/mod_php8.so:
No space available for static Thread Local Storage

PR pkg/56717

--- TSRM/TSRM.h.orig	2024-10-22 18:39:14.000000000 +0000
+++ TSRM/TSRM.h
@@ -149,7 +149,7 @@ TSRM_API bool tsrm_is_managed_thread(voi
 # define __has_attribute(x) 0
 #endif
 
-#if !__has_attribute(tls_model) || defined(__FreeBSD__) || defined(__MUSL__) || defined(__HAIKU__)
+#if !__has_attribute(tls_model) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__MUSL__) || defined(__HAIKU__)
 # define TSRM_TLS_MODEL_ATTR
 # define TSRM_TLS_MODEL_DEFAULT
 #elif __PIC__
