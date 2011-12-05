$NetBSD: patch-plugins_subtitleformats_advancedsubstationalpha_advancedsubstationalpha.cc,v 1.1 2011/12/05 22:53:45 joerg Exp $

--- plugins/subtitleformats/advancedsubstationalpha/advancedsubstationalpha.cc.orig	2011-12-05 21:08:30.000000000 +0000
+++ plugins/subtitleformats/advancedsubstationalpha/advancedsubstationalpha.cc
@@ -24,6 +24,7 @@
 #include <utility.h>
 #include <iomanip>
 #include <document.h>
+#include <cstdio>
 
 /*
  *
