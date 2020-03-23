$NetBSD: patch-svgs_svgs-light_create-logo.sh,v 1.1 2020/03/23 11:57:13 nia Exp $

Portability.

--- svgs/svgs-light/create-logo.sh.orig	2020-02-25 15:41:56.000000000 +0000
+++ svgs/svgs-light/create-logo.sh
@@ -57,7 +57,7 @@ cd ../../bitmaps-light
 rm -f ../Runtime/codelite-bitmaps-light.zip
 zip ../Runtime/codelite-bitmaps-light.zip *.png
 
-if [ "${os_name}" == "Darwin" ]; then
+if [ "${os_name}" = "Darwin" ]; then
     cd osx
     echo iconutil -c icns icon.iconset/
     iconutil -c icns icon.iconset/
