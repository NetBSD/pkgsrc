$NetBSD: patch-src_changes.hh,v 1.1 2026/05/01 05:40:43 wiz Exp $

https://github.com/mawww/kakoune/commit/9d5fb1992e0149130706aa6c9cb3ab474c580597

--- src/changes.hh.orig	2026-05-01 05:39:28.776104724 +0000
+++ src/changes.hh
@@ -4,6 +4,8 @@
 #include "buffer.hh"
 #include "coord.hh"
 
+#include <algorithm>
+
 namespace Kakoune
 {
 
