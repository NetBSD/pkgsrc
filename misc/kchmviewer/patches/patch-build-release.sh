$NetBSD: patch-build-release.sh,v 1.1 2014/11/27 15:32:38 wiz Exp $

Fix unportable test(1) comparison operator.

--- build-release.sh.orig	2014-04-13 08:04:55.000000000 +0000
+++ build-release.sh
@@ -34,7 +34,7 @@ svn export . "$BUILDDIR/" || exit 1
 tar zcf "$RELEASEDIR/$PACKAGE-$CURRENTVER.tar.gz" $BUILDDIR || exit 1
 
 # Build 64-bit onr
-if [ "$BUILD_RPM64" == 1 ]; then
+if [ "$BUILD_RPM64" = 1 ]; then
 
 	# Making the RPM root
 	rm -rf "$BUILDDIR/buildroot"
@@ -57,7 +57,7 @@ if [ "$BUILD_RPM64" == 1 ]; then
 fi
 
 # Build 32-bit RPM
-if [ "$BUILD_RPM32" == 1 ]; then
+if [ "$BUILD_RPM32" = 1 ]; then
 
 	# Clean up first
 	pushd "$BUILDDIR"
@@ -97,7 +97,7 @@ if [ "$BUILD_RPM32" == 1 ]; then
 fi
 
 # win32
-if [ "$BUILD_WINDOWS" == 1 ]; then
+if [ "$BUILD_WINDOWS" = 1 ]; then
 	sh build-win32-mingw.sh || exit 1
 	(cd nsis && sh create_installer.sh) || exit 1
 	mv nsis/InstallKchmviewer*.exe $RELEASEDIR
