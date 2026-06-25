$NetBSD: patch-src_database_search__handler.h,v 1.1 2026/06/25 08:16:53 wiz Exp $

Fix build.
https://github.com/gerbera/gerbera/issues/3897

--- src/database/search_handler.h.orig	2026-06-25 07:59:32.782514264 +0000
+++ src/database/search_handler.h
@@ -33,6 +33,7 @@
 
 #include <algorithm>
 #include <fmt/core.h>
+#include <fmt/format.h>
 #include <map>
 #include <memory>
 #include <tuple>
