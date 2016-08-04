$NetBSD: patch-config.m4,v 1.1 2016/08/04 16:03:53 jdolecek Exp $

--- config.m4.orig	2016-08-04 15:57:53.000000000 +0000
+++ config.m4
@@ -468,11 +468,11 @@ dnl }}}
   PHP_ADD_BUILD_DIR([$ext_builddir/src/MongoDB/])
   PHP_ADD_BUILD_DIR([$ext_builddir/src/MongoDB/Exception/])
   PHP_ADD_BUILD_DIR([$ext_builddir/src/contrib/])
-  if test "$PHP_LIBMONGOC" == "no"; then
+  if test "$PHP_LIBMONGOC" = "no"; then
     PHP_ADD_INCLUDE([$ext_srcdir/src/libmongoc/src/mongoc/])
     PHP_ADD_BUILD_DIR([$ext_builddir/src/libmongoc/src/mongoc/])
   fi
-  if test "$PHP_LIBBSON" == "no"; then
+  if test "$PHP_LIBBSON" = "no"; then
     m4_include(src/libbson/build/autotools/CheckAtomics.m4)
     m4_include(src/libbson/build/autotools/FindDependencies.m4)
     m4_include(src/libbson/build/autotools/m4/ac_compile_check_sizeof.m4)
@@ -517,7 +517,7 @@ dnl }}}
     AC_SUBST(BSON_HAVE_SNPRINTF, 0)
   fi
 
-  if test "$PHP_LIBMONGOC" == "no"; then
+  if test "$PHP_LIBMONGOC" = "no"; then
     backup_srcdir=${srcdir}
     srcdir=${srcdir}/src/libmongoc/
     m4_include(src/libmongoc/build/autotools/Versions.m4)
@@ -531,7 +531,7 @@ dnl }}}
     AC_OUTPUT($srcdir/src/libmongoc/src/mongoc/mongoc-config.h)
     AC_OUTPUT($srcdir/src/libmongoc/src/mongoc/mongoc-version.h)
   fi
-  if test "$PHP_LIBBSON" == "no"; then
+  if test "$PHP_LIBBSON" = "no"; then
     backup_srcdir=${srcdir}
     srcdir=${srcdir}/src/libbson/
     m4_include(src/libbson/build/autotools/Versions.m4)
