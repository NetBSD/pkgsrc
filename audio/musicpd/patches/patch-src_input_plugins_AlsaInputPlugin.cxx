$NetBSD: patch-src_input_plugins_AlsaInputPlugin.cxx,v 1.1 2026/06/25 07:29:21 wiz Exp $

libfmt 12.2.0 support: use fmt/format.h not fmt/core.h
https://github.com/MusicPlayerDaemon/MPD/pull/2512/changes

--- src/input/plugins/AlsaInputPlugin.cxx.orig	2026-05-15 05:46:52.000000000 +0000
+++ src/input/plugins/AlsaInputPlugin.cxx
@@ -27,7 +27,7 @@
 
 #include <alsa/asoundlib.h>
 
-#include <fmt/core.h>
+#include <fmt/format.h>
 
 #include <cassert>
 
