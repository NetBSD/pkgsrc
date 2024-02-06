$NetBSD: patch-src_af_util_xp_ut__stringbuf.cpp,v 1.1 2024/02/06 03:48:34 gutteridge Exp $

Fix builds with libxml2 2.12.

--- src/af/util/xp/ut_stringbuf.cpp.orig	2021-07-03 15:46:07.000000000 +0000
+++ src/af/util/xp/ut_stringbuf.cpp
@@ -26,6 +26,7 @@
 #include <algorithm>
 
 #include <libxml/uri.h>
+#include <libxml/xmlmemory.h>
 
 #include <glib.h>
 
