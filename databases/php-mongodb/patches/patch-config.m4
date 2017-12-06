$NetBSD: patch-config.m4,v 1.2 2017/12/06 21:18:00 jdolecek Exp $

--- config.m4.orig	2017-12-01 18:41:35.000000000 +0000
+++ config.m4
@@ -216,7 +216,7 @@ if test "$MONGODB" != "no"; then
   [  --with-libmongoc           Use system libmongoc], no, no)
 
   if test "$PHP_LIBBSON" != "no"; then
-    if test "$PHP_LIBMONGOC" == "no"; then
+    if test "$PHP_LIBMONGOC" = "no"; then
       AC_MSG_ERROR(Cannot use system libbson and bundled libmongoc)
     fi
 
@@ -254,7 +254,7 @@ if test "$MONGODB" != "no"; then
   AC_MSG_RESULT(...)
 
   if test "$PHP_LIBMONGOC" != "no"; then
-    if test "$PHP_LIBBSON" == "no"; then
+    if test "$PHP_LIBBSON" = "no"; then
       AC_MSG_ERROR(Cannot use system libmongoc and bundled libbson)
     fi
 
@@ -402,11 +402,11 @@ if test "$MONGODB" != "no"; then
   PHP_ADD_BUILD_DIR([$ext_builddir/src/MongoDB/Exception/])
   PHP_ADD_BUILD_DIR([$ext_builddir/src/MongoDB/Monitoring/])
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
@@ -449,7 +449,7 @@ if test "$MONGODB" != "no"; then
     AC_SUBST(BSON_HAVE_SNPRINTF, 0)
   fi
 
-  if test "$PHP_LIBMONGOC" == "no"; then
+  if test "$PHP_LIBMONGOC" = "no"; then
     backup_srcdir=${srcdir}
     srcdir=${srcdir}/src/libmongoc/
     m4_include(src/libmongoc/build/autotools/Versions.m4)
@@ -463,7 +463,7 @@ if test "$MONGODB" != "no"; then
     AC_OUTPUT($srcdir/src/libmongoc/src/mongoc/mongoc-config.h)
     AC_OUTPUT($srcdir/src/libmongoc/src/mongoc/mongoc-version.h)
   fi
-  if test "$PHP_LIBBSON" == "no"; then
+  if test "$PHP_LIBBSON" = "no"; then
     backup_srcdir=${srcdir}
     srcdir=${srcdir}/src/libbson/
     m4_include(src/libbson/build/autotools/Versions.m4)
