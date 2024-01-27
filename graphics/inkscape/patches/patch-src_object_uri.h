$NetBSD: patch-src_object_uri.h,v 1.1 2024/01/27 18:16:39 wiz Exp $

Fix build with libxml2 2.12.
https://gitlab.com/inkscape/inkscape/-/merge_requests/6089/diffs

--- src/object/uri.h.orig	2024-01-27 18:07:45.846366553 +0000
+++ src/object/uri.h
@@ -13,6 +13,7 @@
 #define INKSCAPE_URI_H
 
 #include <libxml/uri.h>
+#include <libxml/xmlmemory.h>
 #include <memory>
 #include <string>
 
