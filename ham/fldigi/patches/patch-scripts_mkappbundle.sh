$NetBSD: patch-scripts_mkappbundle.sh,v 1.1 2020/12/06 00:22:04 dbj Exp $

Do not build the disk image on Darwin.
This would not be an issue except it requires write access to /dev/*
and fails if sandboxed off.  This is not used by pkgsrc anyway.

--- scripts/mkappbundle.sh.orig	2018-03-21 15:16:19.000000000 +0000
+++ scripts/mkappbundle.sh
@@ -123,7 +123,7 @@ if test "x$WANT_FLARQ" = "xyes"; then
 	bundle
 fi
 
-cd "$build"
-
-echo "creating disk image"
-hdiutil create -ov -srcfolder "$bundle_dir" -format UDZO -tgtimagekey zlib-level=9 "${APPBUNDLE}.dmg"
+#cd "$build"
+#
+#echo "creating disk image"
+#hdiutil create -ov -srcfolder "$bundle_dir" -format UDZO -tgtimagekey zlib-level=9 "${APPBUNDLE}.dmg"
