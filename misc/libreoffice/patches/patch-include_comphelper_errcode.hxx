$NetBSD: patch-include_comphelper_errcode.hxx,v 1.1 2024/02/11 15:31:58 ryoon Exp $

--- include/comphelper/errcode.hxx.orig	2024-02-01 12:49:34.343781328 +0000
+++ include/comphelper/errcode.hxx
@@ -23,6 +23,7 @@
 #include <ostream>
 #include <o3tl/typed_flags_set.hxx>
 #include <optional>
+#include <climits>
 
 #if defined(DBG_UTIL)
 #if __has_include(<version>)
