$NetBSD: patch-doc_python_api_sphinx_doc_gen.sh,v 1.1 2015/12/15 09:46:27 markd Exp $

--- doc/python_api/sphinx_doc_gen.sh.orig	2015-03-25 11:01:16.000000000 +0000
+++ doc/python_api/sphinx_doc_gen.sh
@@ -3,7 +3,7 @@
 #   bash doc/python_api/sphinx_doc_gen.sh
 # ssh upload means you need an account on the server
 
-if [ "$1" == "" ] ; then
+if [ "$1" = "" ] ; then
 	echo "Expected a single argument for the username on blender.org, aborting"
 	exit 1
 fi
