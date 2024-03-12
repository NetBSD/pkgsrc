$NetBSD: patch-bootstrap.sh,v 1.1 2024/03/12 17:50:13 wiz Exp $

Fix out-of-tree bootstrap build and fix link time warning on NetBSD

--- bootstrap.sh.orig	2023-10-09 21:31:11.000000000 +0300
+++ bootstrap.sh	2024-03-12 11:02:08.865606070 +0200
@@ -90,13 +90,16 @@
 UName=`uname | cut -b -5`
 PutUsage=gpr/src/gpr-util-put_resource_usage
 
-rm -f ${PutUsage}.adb
+rm -f ${srcdir}/${PutUsage}.adb
 
 if [ "$UName" = "CYGWI" ] || [ "$UName" = "MINGW" ]
 then
-	cp ${PutUsage}__null.adb ${PutUsage}.adb
+	cp ${srcdir}/${PutUsage}__null.adb ${srcdir}/${PutUsage}.adb
+elif [ "$UName" = "NetBS" ]
+then
+	ln ${srcdir}/${PutUsage}__netbsd.adb ${srcdir}/${PutUsage}.adb
 else
-	ln -s $PWD/${PutUsage}__unix.adb ${PutUsage}.adb
+	ln -s ${srcdir}/${PutUsage}__unix.adb ${srcdir}/${PutUsage}.adb
 fi
 
 # Build
