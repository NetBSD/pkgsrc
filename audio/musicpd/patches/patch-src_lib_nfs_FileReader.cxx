$NetBSD: patch-src_lib_nfs_FileReader.cxx,v 1.1 2026/06/25 07:29:22 wiz Exp $

libfmt 12.2.0 support: use fmt/format.h not fmt/core.h
https://github.com/MusicPlayerDaemon/MPD/pull/2512/changes

--- src/lib/nfs/FileReader.cxx.orig	2026-05-15 05:46:52.000000000 +0000
+++ src/lib/nfs/FileReader.cxx
@@ -10,7 +10,7 @@
 
 #include <nfsc/libnfs.h> // for struct nfs_stat_64
 
-#include <fmt/core.h>
+#include <fmt/format.h>
 
 #include <cassert>
 #include <cstring>
