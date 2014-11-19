$NetBSD: patch-m4_buildsys.m4,v 1.1 2014/11/19 03:37:14 schmonz Exp $

Correct path to dovecot plugins.

--- m4/buildsys.m4.orig	2013-04-29 12:59:26.000000000 +0000
+++ m4/buildsys.m4
@@ -103,7 +103,7 @@ AC_DEFUN([BUILDSYS_SHARED_LIB], [
 			LIB_LDFLAGS='-dynamiclib -current_version ${LIB_MAJOR}.${LIB_MINOR} -compatibility_version ${LIB_MAJOR}'
 			LIB_PREFIX='lib'
 			LIB_SUFFIX='.dylib'
-			LDFLAGS_RPATH='-Wl,-rpath,${libdir}'
+			LDFLAGS_RPATH='-Wl,-rpath,${libdir}/dovecot'
 			PLUGIN_CFLAGS='-fPIC -DPIC'
 			PLUGIN_LDFLAGS='-bundle -undefined dynamic_lookup'
 			PLUGIN_SUFFIX='.bundle'
@@ -117,7 +117,7 @@ AC_DEFUN([BUILDSYS_SHARED_LIB], [
 			LIB_LDFLAGS='-shared -Wl,-soname=${SHARED_LIB}.${LIB_MAJOR}.${LIB_MINOR}'
 			LIB_PREFIX='lib'
 			LIB_SUFFIX='.so'
-			LDFLAGS_RPATH='-Wl,-rpath,${libdir}'
+			LDFLAGS_RPATH='-Wl,-rpath,${libdir}/dovecot'
 			PLUGIN_CFLAGS='-fPIC -DPIC'
 			PLUGIN_LDFLAGS='-shared'
 			PLUGIN_SUFFIX='.so'
@@ -131,7 +131,7 @@ AC_DEFUN([BUILDSYS_SHARED_LIB], [
 			LIB_LDFLAGS='-shared'
 			LIB_PREFIX='lib'
 			LIB_SUFFIX='.so.${LIB_MAJOR}.${LIB_MINOR}'
-			LDFLAGS_RPATH='-Wl,-rpath,${libdir}'
+			LDFLAGS_RPATH='-Wl,-rpath,${libdir}/dovecot'
 			PLUGIN_CFLAGS='-fPIC -DPIC'
 			PLUGIN_LDFLAGS='-shared'
 			PLUGIN_SUFFIX='.so'
@@ -145,7 +145,7 @@ AC_DEFUN([BUILDSYS_SHARED_LIB], [
 			LIB_LDFLAGS='-shared -Wl,--out-implib,${SHARED_LIB}.a'
 			LIB_PREFIX='lib'
 			LIB_SUFFIX='.dll'
-			LDFLAGS_RPATH='-Wl,-rpath,${libdir}'
+			LDFLAGS_RPATH='-Wl,-rpath,${libdir}/dovecot'
 			PLUGIN_CFLAGS=''
 			PLUGIN_LDFLAGS='-shared'
 			PLUGIN_SUFFIX='.dll'
@@ -159,7 +159,7 @@ AC_DEFUN([BUILDSYS_SHARED_LIB], [
 			LIB_LDFLAGS='-shared -Wl,-soname=${SHARED_LIB}.${LIB_MAJOR}'
 			LIB_PREFIX='lib'
 			LIB_SUFFIX='.so'
-			LDFLAGS_RPATH='-Wl,-rpath,${libdir}'
+			LDFLAGS_RPATH='-Wl,-rpath,${libdir}/dovecot'
 			PLUGIN_CFLAGS='-fPIC -DPIC'
 			PLUGIN_LDFLAGS='-shared'
 			PLUGIN_SUFFIX='.so'
