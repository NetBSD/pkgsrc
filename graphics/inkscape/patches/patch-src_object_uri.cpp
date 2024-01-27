$NetBSD: patch-src_object_uri.cpp,v 1.1 2024/01/27 15:47:06 wiz Exp $

Fix build with libxml2 2.12.

--- src/object/uri.cpp.orig	2024-01-27 15:42:32.772579666 +0000
+++ src/object/uri.cpp
@@ -19,6 +19,7 @@
 #include <glibmm/convert.h>
 #include <glibmm/ustring.h>
 #include <glibmm/miscutils.h>
+#include <libxml/xmlmemory.h>
 
 #include "bad-uri-exception.h"
 
