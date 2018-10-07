$NetBSD: patch-doc_python__api_sphinx__doc__gen.sh,v 1.5 2018/10/07 23:44:49 ryoon Exp $

--- doc/python_api/sphinx_doc_gen.sh.orig	2018-02-20 09:26:28.000000000 +0000
+++ doc/python_api/sphinx_doc_gen.sh
@@ -17,7 +17,7 @@ if [ -z $BLENDER_BIN ] ; then
 	BLENDER_BIN="./blender.bin"
 fi
 
-if [ "$1" == "" ] ; then
+if [ "$1" = "" ] ; then
 	echo "Expected a single argument for the username on blender.org, skipping upload step!"
 	DO_UPLOAD=false
 else
