$NetBSD: patch-uf__glib.h,v 1.1 2023/08/04 13:11:24 gdt Exp $

Avoid extern C around glib includes.  Apparently they do C++ things
when compiled in C++ mode and this causes gcc10 to complain.

Not sent upstream because upstream does not seem to be maintaining
this.

--- uf_glib.h.orig	2015-06-16 03:58:38.000000000 +0000
+++ uf_glib.h
@@ -13,13 +13,13 @@
 #ifndef _UF_GLIB_H
 #define _UF_GLIB_H
 
+#include <glib.h>
+#include <glib/gstdio.h>
+
 #ifdef __cplusplus
 extern "C" {
 #endif
 
-#include <glib.h>
-#include <glib/gstdio.h>
-
 // g_win32_locale_filename_from_utf8 is needed only on win32
 #ifdef _WIN32
 #define uf_win32_locale_filename_from_utf8(__some_string__) \
