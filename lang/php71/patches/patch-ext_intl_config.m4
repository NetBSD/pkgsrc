$NetBSD: patch-ext_intl_config.m4,v 1.1.12.1 2018/05/06 10:48:47 spz Exp $

Work around for build problem.

--- ext/intl/config.m4.orig	2018-04-24 16:17:57.000000000 +0000
+++ ext/intl/config.m4
@@ -68,7 +68,7 @@ if test "$PHP_INTL" != "no"; then
     transliterator/transliterator_methods.c \
     uchar/uchar.c \
     idn/idn.c \
-    $icu_spoof_src, $ext_shared,,$INTL_COMMON_FLAGS,cxx)
+    $icu_spoof_src, $ext_shared,,$INTL_COMMON_FLAGS)
 
   PHP_INTL_CXX_SOURCES="intl_convertcpp.cpp \
     common/common_enum.cpp \
