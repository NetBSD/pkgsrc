$NetBSD: patch-bootstrap.sh,v 1.4 2025/10/09 15:46:43 dkazankov Exp $

Fix out-of-tree bootstrap build

--- bootstrap.sh.orig	2023-10-09 21:31:11.000000000 +0300
+++ bootstrap.sh
@@ -90,13 +90,13 @@
 UName=`uname | cut -b -5`
 PutUsage=gpr/src/gpr-util-put_resource_usage
 
-rm -f ${PutUsage}.adb
+rm -f ${srcdir}/${PutUsage}.adb
 
 if [ "$UName" = "CYGWI" ] || [ "$UName" = "MINGW" ]
 then
-	cp ${PutUsage}__null.adb ${PutUsage}.adb
+	cp ${srcdir}/${PutUsage}__null.adb ${srcdir}/${PutUsage}.adb
 else
-	ln -s $PWD/${PutUsage}__unix.adb ${PutUsage}.adb
+	ln -s ${srcdir}/${PutUsage}__unix.adb ${srcdir}/${PutUsage}.adb
 fi
 
 # Build
