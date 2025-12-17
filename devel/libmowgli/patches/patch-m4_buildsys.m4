$NetBSD: patch-m4_buildsys.m4,v 1.1 2025/12/17 22:09:15 nia Exp $

Install libraries consistently across ELF platforms.

--- m4/buildsys.m4.orig	2017-09-15 22:17:58.000000000 +0000
+++ m4/buildsys.m4
@@ -116,8 +116,8 @@ AC_DEFUN([BUILDSYS_SHARED_LIB], [
 			PLUGIN_CFLAGS='-fPIC -DPIC'
 			PLUGIN_LDFLAGS='-shared'
 			PLUGIN_SUFFIX='.so'
-			INSTALL_LIB='&& ${INSTALL} -m 755 $$i ${DESTDIR}${libdir}/$$i.${LIB_MAJOR}.${LIB_MINOR} && rm -f ${DESTDIR}${libdir}/$$i && ${LN_S} $$i.${LIB_MAJOR}.${LIB_MINOR} ${DESTDIR}${libdir}/$$i'
-			UNINSTALL_LIB='&& rm -f ${DESTDIR}${libdir}/$$i ${DESTDIR}${libdir}/$$i.${LIB_MAJOR}.${LIB_MINOR}'
+			INSTALL_LIB='&& ${INSTALL} -m 755 $$i ${DESTDIR}${libdir}/$$i.${LIB_MAJOR}.${LIB_MINOR}.0 && ${LN_S} -f $$i.${LIB_MAJOR}.${LIB_MINOR}.0 ${DESTDIR}${libdir}/$$i.${LIB_MAJOR} && ${LN_S} -f $$i.${LIB_MAJOR}.${LIB_MINOR}.0 ${DESTDIR}${libdir}/$$i'
+			UNINSTALL_LIB='&& rm -f ${DESTDIR}${libdir}/$$i ${DESTDIR}${libdir}/$$i.${LIB_MAJOR} ${DESTDIR}${libdir}/$$i.${LIB_MAJOR}.${LIB_MINOR}.0'
 			CLEAN_LIB=''
 			;;
 		openbsd* | mirbsd*)
@@ -125,13 +125,13 @@ AC_DEFUN([BUILDSYS_SHARED_LIB], [
 			LIB_CFLAGS='-fPIC -DPIC'
 			LIB_LDFLAGS='-shared'
 			LIB_PREFIX='lib'
-			LIB_SUFFIX='.so.${LIB_MAJOR}.${LIB_MINOR}'
+			LIB_SUFFIX='.so'
 			LDFLAGS_RPATH='-Wl,-rpath,${libdir}'
 			PLUGIN_CFLAGS='-fPIC -DPIC'
 			PLUGIN_LDFLAGS='-shared'
 			PLUGIN_SUFFIX='.so'
-			INSTALL_LIB='&& ${INSTALL} -m 755 $$i ${DESTDIR}${libdir}/$$i'
-			UNINSTALL_LIB='&& rm -f ${DESTDIR}${libdir}/$$i'
+			INSTALL_LIB='&& ${INSTALL} -m 755 $$i ${DESTDIR}${libdir}/$$i.${LIB_MAJOR}.${LIB_MINOR}.0 && ${LN_S} -f $$i.${LIB_MAJOR}.${LIB_MINOR}.0 ${DESTDIR}${libdir}/$$i.${LIB_MAJOR} && ${LN_S} -f $$i.${LIB_MAJOR}.${LIB_MINOR}.0 ${DESTDIR}${libdir}/$$i'
+			UNINSTALL_LIB='&& rm -f ${DESTDIR}${libdir}/$$i ${DESTDIR}${libdir}/$$i.${LIB_MAJOR} ${DESTDIR}${libdir}/$$i.${LIB_MAJOR}.${LIB_MINOR}.0'
 			CLEAN_LIB=''
 			;;
 		cygwin* | mingw*)
@@ -144,8 +144,8 @@ AC_DEFUN([BUILDSYS_SHARED_LIB], [
 			PLUGIN_CFLAGS=''
 			PLUGIN_LDFLAGS='-shared'
 			PLUGIN_SUFFIX='.dll'
-			INSTALL_LIB='&& ${MKDIR_P} ${DESTDIR}${bindir} && ${INSTALL} -m 755 $$i ${DESTDIR}${bindir}/$$i && ${INSTALL} -m 755 $$i.a ${DESTDIR}${libdir}/$$i.a'
-			UNINSTALL_LIB='&& rm -f ${DESTDIR}${bindir}/$$i ${DESTDIR}${libdir}/$$i.a'
+			INSTALL_LIB='&& ${INSTALL} -m 755 $$i ${DESTDIR}${libdir}/$$i.${LIB_MAJOR}.${LIB_MINOR}.0 && ${LN_S} -f $$i.${LIB_MAJOR}.${LIB_MINOR}.0 ${DESTDIR}${libdir}/$$i.${LIB_MAJOR} && ${LN_S} -f $$i.${LIB_MAJOR}.${LIB_MINOR}.0 ${DESTDIR}${libdir}/$$i'
+			UNINSTALL_LIB='&& rm -f ${DESTDIR}${libdir}/$$i ${DESTDIR}${libdir}/$$i.${LIB_MAJOR} ${DESTDIR}${libdir}/$$i.${LIB_MAJOR}.${LIB_MINOR}.0'
 			CLEAN_LIB='${SHARED_LIB}.a'
 			;;
 		*)
