$NetBSD: patch-src_net_ToString.cxx,v 1.1 2026/06/25 07:29:22 wiz Exp $

libfmt 12.2.0 support: use fmt/format.h not fmt/core.h
https://github.com/MusicPlayerDaemon/MPD/pull/2512/changes

--- src/net/ToString.cxx.orig	2026-05-15 05:46:52.000000000 +0000
+++ src/net/ToString.cxx
@@ -6,7 +6,7 @@
 #include "SocketAddress.hxx"
 #include "IPv4Address.hxx"
 
-#include <fmt/core.h>
+#include <fmt/format.h>
 
 #include <algorithm>
 #include <cassert>
