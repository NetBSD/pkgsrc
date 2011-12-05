$NetBSD: patch-plugins_subtitleformats_substationalpha_substationalpha.cc,v 1.1 2011/12/05 22:53:45 joerg Exp $

--- plugins/subtitleformats/substationalpha/substationalpha.cc.orig	2011-12-05 21:10:29.000000000 +0000
+++ plugins/subtitleformats/substationalpha/substationalpha.cc
@@ -23,6 +23,7 @@
 #include <extension/subtitleformat.h>
 #include <utility.h>
 #include <iomanip>
+#include <cstdio>
 
 
 class SubStationAlpha : public SubtitleFormatIO
