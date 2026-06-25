$NetBSD: patch-src_storage_plugins_NfsStorage.cxx,v 1.1 2026/06/25 07:29:22 wiz Exp $

libfmt 12.2.0 support: use fmt/format.h not fmt/core.h
https://github.com/MusicPlayerDaemon/MPD/pull/2512/changes

--- src/storage/plugins/NfsStorage.cxx.orig	2026-05-15 05:46:52.000000000 +0000
+++ src/storage/plugins/NfsStorage.cxx
@@ -29,7 +29,7 @@ extern "C" {
 #include <nfsc/libnfs-raw-nfs.h>
 }
 
-#include <fmt/core.h>
+#include <fmt/format.h>
 
 #include <cassert>
 #include <string>
