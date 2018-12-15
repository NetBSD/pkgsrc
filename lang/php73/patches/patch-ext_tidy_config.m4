$NetBSD: patch-ext_tidy_config.m4,v 1.1 2018/12/15 17:12:44 taca Exp $

--- ext/tidy/config.m4.orig	2018-12-04 16:12:28.000000000 +0000
+++ ext/tidy/config.m4
@@ -40,7 +40,7 @@ if test "$PHP_TIDY" != "no"; then
   fi
 
   TIDY_LIBDIR=$TIDY_DIR/$PHP_LIBDIR
-  if test "$TIDY_LIB_NAME" == 'tidyp'; then
+  if test "$TIDY_LIB_NAME" = 'tidyp'; then
     AC_DEFINE(HAVE_TIDYP_H,1,[defined if tidyp.h exists])
   else
     AC_DEFINE(HAVE_TIDY_H,1,[defined if tidy.h exists])
