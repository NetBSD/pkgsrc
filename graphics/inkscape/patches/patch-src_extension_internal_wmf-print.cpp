$NetBSD: patch-src_extension_internal_wmf-print.cpp,v 1.1 2018/06/28 11:18:59 jperkin Exp $

Avoid ambiguous function calls.

--- src/extension/internal/wmf-print.cpp.orig	2017-08-06 20:44:00.000000000 +0000
+++ src/extension/internal/wmf-print.cpp
@@ -67,6 +67,8 @@
 #include <string.h>
 #include <libuemf/symbol_convert.h>
 
+using std::sqrt;
+
 namespace Inkscape {
 namespace Extension {
 namespace Internal {
