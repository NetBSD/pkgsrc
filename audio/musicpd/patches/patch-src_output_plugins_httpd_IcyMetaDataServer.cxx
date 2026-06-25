$NetBSD: patch-src_output_plugins_httpd_IcyMetaDataServer.cxx,v 1.1 2026/06/25 07:29:22 wiz Exp $

libfmt 12.2.0 support: use fmt/format.h not fmt/core.h
https://github.com/MusicPlayerDaemon/MPD/pull/2512/changes

--- src/output/plugins/httpd/IcyMetaDataServer.cxx.orig	2026-05-15 05:46:52.000000000 +0000
+++ src/output/plugins/httpd/IcyMetaDataServer.cxx
@@ -5,7 +5,7 @@
 #include "tag/Tag.hxx"
 #include "util/TruncateString.hxx"
 
-#include <fmt/core.h>
+#include <fmt/format.h>
 
 #include <iterator>
 
