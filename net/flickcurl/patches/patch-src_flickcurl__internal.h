$NetBSD: patch-src_flickcurl__internal.h,v 1.2 2011/08/29 14:45:46 wiz Exp $

Compatibility with latest curl.

--- src/flickcurl_internal.h.orig	2010-07-24 19:33:34.000000000 +0000
+++ src/flickcurl_internal.h
@@ -24,7 +24,6 @@
 #include <libxml/xpath.h>
 
 #include <curl/curl.h>
-#include <curl/types.h>
 #include <curl/easy.h>
 
 
