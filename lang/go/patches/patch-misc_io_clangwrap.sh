$NetBSD: patch-misc_io_clangwrap.sh,v 1.1 2015/12/10 20:04:54 bsiegert Exp $

--- misc/ios/clangwrap.sh.orig	2015-12-03 00:52:58.000000000 +0000
+++ misc/ios/clangwrap.sh
@@ -8,9 +8,9 @@ export IPHONEOS_DEPLOYMENT_TARGET=5.1
 # cmd/cgo doesn't support llvm-gcc-4.2, so we have to use clang.
 CLANG=`xcrun --sdk $SDK --find clang`
 
-if [ "$GOARCH" == "arm" ]; then
+if [ "$GOARCH" = "arm" ]; then
 	CLANGARCH="armv7"
-elif [ "$GOARCH" == "arm64" ]; then
+elif [ "$GOARCH" = "arm64" ]; then
 	CLANGARCH="arm64"
 else
 	echo "unknown GOARCH=$GOARCH" >&2
