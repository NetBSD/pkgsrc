$NetBSD: patch-include_comphelper_errcode.hxx,v 1.2 2024/08/24 02:57:35 ryoon Exp $

--- include/comphelper/errcode.hxx.orig	2024-08-22 12:18:16.158178965 +0000
+++ include/comphelper/errcode.hxx
@@ -25,6 +25,7 @@
 #include <o3tl/typed_flags_set.hxx>
 #include <optional>
 #include <compare>
+#include <climits>
 
 #if defined(DBG_UTIL)
 #if __has_include(<version>)
