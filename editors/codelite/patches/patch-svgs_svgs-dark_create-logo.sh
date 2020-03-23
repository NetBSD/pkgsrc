$NetBSD: patch-svgs_svgs-dark_create-logo.sh,v 1.1 2020/03/23 11:57:13 nia Exp $

Portability.

--- svgs/svgs-dark/create-logo.sh.orig	2020-02-25 15:41:56.000000000 +0000
+++ svgs/svgs-dark/create-logo.sh
@@ -57,7 +57,7 @@ cd ../../bitmaps-dark
 rm -f ../Runtime/codelite-bitmaps-dark.zip
 zip ../Runtime/codelite-bitmaps-dark.zip *.png
 
-if [ "${os_name}" == "Darwin" ]; then
+if [ "${os_name}" = "Darwin" ]; then
     cd osx
     echo iconutil -c icns icon.iconset/
     iconutil -c icns icon.iconset/
