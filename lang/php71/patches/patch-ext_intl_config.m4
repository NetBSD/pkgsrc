$NetBSD: patch-ext_intl_config.m4,v 1.1 2017/02/20 03:23:13 taca Exp $

Work around for build problem.

--- ext/intl/config.m4.orig	2017-02-14 18:35:43.000000000 +0000
+++ ext/intl/config.m4
@@ -86,7 +86,7 @@ if test "$PHP_INTL" != "no"; then
     breakiterator/codepointiterator_methods.cpp \
     uchar/uchar.c \
     idn/idn.c \
-    $icu_spoof_src, $ext_shared,,$ICU_INCS -Wno-write-strings -D__STDC_LIMIT_MACROS -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1,cxx)
+    $icu_spoof_src, $ext_shared,,$ICU_INCS -Wno-write-strings -D__STDC_LIMIT_MACROS -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1)
   PHP_ADD_BUILD_DIR($ext_builddir/collator)
   PHP_ADD_BUILD_DIR($ext_builddir/converter)
   PHP_ADD_BUILD_DIR($ext_builddir/common)
