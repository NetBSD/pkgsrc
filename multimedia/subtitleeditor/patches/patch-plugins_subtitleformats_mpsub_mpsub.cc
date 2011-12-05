$NetBSD: patch-plugins_subtitleformats_mpsub_mpsub.cc,v 1.1 2011/12/05 22:53:45 joerg Exp $

--- plugins/subtitleformats/mpsub/mpsub.cc.orig	2011-12-05 21:09:35.000000000 +0000
+++ plugins/subtitleformats/mpsub/mpsub.cc
@@ -22,6 +22,7 @@
 
 #include <extension/subtitleformat.h>
 #include <utility.h>
+#include <cstdio>
 
 /*
  *
