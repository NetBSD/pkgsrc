$NetBSD: patch-src_extension_internal_metafile-print.cpp,v 1.1 2018/06/28 11:18:59 jperkin Exp $

Avoid ambiguous function calls.

--- src/extension/internal/metafile-print.cpp.orig	2017-08-06 20:44:00.000000000 +0000
+++ src/extension/internal/metafile-print.cpp
@@ -30,6 +30,9 @@
 #include "sp-radial-gradient.h"
 #include "style.h"
 
+using std::cos;
+using std::sin;
+
 namespace Inkscape {
 namespace Extension {
 namespace Internal {
