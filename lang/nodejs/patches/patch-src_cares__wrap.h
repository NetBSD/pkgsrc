$NetBSD: patch-src_cares__wrap.h,v 1.3 2026/08/21 09:37:13 khorben Exp $

Fix this error during the build:

../src/cares_wrap.cc:1740:3: error: no matching function for call to 'ares_gethostbyaddr'

--- src/cares_wrap.h.orig	2026-08-21 09:32:41.423565063 +0000
+++ src/cares_wrap.h
@@ -352,7 +352,7 @@ class QueryWrap final : public AsyncWrap
       void* arg,
       int status,
       int timeouts,
-      struct hostent* host) {
+      const struct hostent* host) {
     QueryWrap<Traits>* wrap = FromCallbackPointer(arg);
     if (wrap == nullptr) return;
 
