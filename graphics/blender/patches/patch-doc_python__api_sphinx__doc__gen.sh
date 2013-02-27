$NetBSD: patch-doc_python__api_sphinx__doc__gen.sh,v 1.2 2013/02/27 15:25:28 ryoon Exp $

* Improve portability

--- doc/python_api/sphinx_doc_gen.sh.orig	2013-02-20 14:22:36.000000000 +0000
+++ doc/python_api/sphinx_doc_gen.sh
@@ -32,7 +32,7 @@ blender_version_char=$(grep BLENDER_VERS
 blender_version_cycle=$(grep BLENDER_VERSION_CYCLE $blender_srcdir/source/blender/blenkernel/BKE_blender.h | awk '{print $3}')
 blender_subversion=$(grep BLENDER_SUBVERSION $blender_srcdir/source/blender/blenkernel/BKE_blender.h | awk '{print $3}')
 
-if [ "$blender_version_cycle" == "release" ] ; then
+if [ "$blender_version_cycle" = "release" ] ; then
 	BLENDER_VERSION=$(expr $blender_version / 100)_$(expr $blender_version % 100)$blender_version_char"_release"
 else
 	BLENDER_VERSION=$(expr $blender_version / 100)_$(expr $blender_version % 100)_$blender_subversion
@@ -109,7 +109,7 @@ if $DO_UPLOAD ; then
 	ssh $SSH_USER@emo.blender.org 'echo "<html><head><title>Redirecting...</title><meta http-equiv=\"REFRESH\" content=\"0;url=../blender_python_api_'$BLENDER_VERSION'/\"></head><body>Redirecting...</body></html>" > '$SSH_UPLOAD'/250PythonDoc/index.html'
 
 	# redirect for release only so wiki can point here
-	if [ "$blender_version_cycle" == "release" ] ; then
+	if [ "$blender_version_cycle" = "release" ] ; then
 		ssh $SSH_USER@emo.blender.org 'echo "<html><head><title>Redirecting...</title><meta http-equiv=\"REFRESH\" content=\"0;url=../blender_python_api_'$BLENDER_VERSION'/\"></head><body>Redirecting...</body></html>" > '$SSH_UPLOAD'/blender_python_api/index.html'
 	fi
 
