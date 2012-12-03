$NetBSD: patch-doc_python__api_sphinx__doc__gen.sh,v 1.1 2012/12/03 13:15:51 ryoon Exp $

* Improve portability

--- doc/python_api/sphinx_doc_gen.sh.orig	2012-10-09 18:42:01.000000000 +0000
+++ doc/python_api/sphinx_doc_gen.sh
@@ -32,7 +32,7 @@ blender_version_char=$(grep BLENDER_VERS
 blender_version_cycle=$(grep BLENDER_VERSION_CYCLE $blender_srcdir/source/blender/blenkernel/BKE_blender.h | awk '{print $3}')
 blender_subversion=$(grep BLENDER_SUBVERSION $blender_srcdir/source/blender/blenkernel/BKE_blender.h | awk '{print $3}')
 
-if [ "$blender_version_cycle" == "release" ]
+if [ "$blender_version_cycle" = "release" ]
 then
 	BLENDER_VERSION=$(expr $blender_version / 100)_$(expr $blender_version % 100)$blender_version_char"_release"
 else
