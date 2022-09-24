$NetBSD: patch-libelemental_value.cc,v 1.2 2022/09/24 06:30:44 wiz Exp $

Fix build with pango 1.50.
https://github.com/ginggs/gelemental/commit/689d343086ca151ecc4c4a407c1650bc64c7c931

--- libelemental/value.cc.orig	2021-09-26 09:22:33.000000000 +0000
+++ libelemental/value.cc
@@ -25,7 +25,7 @@
 
 #include <ext/stdio_filebuf.h>
 #include <glibmm/utility.h>
-#include <pango/pango-attributes.h>
+#include <pango/pango.h>
 
 namespace Elemental {
 
