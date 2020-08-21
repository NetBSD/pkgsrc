$NetBSD: patch-misc_io_clangwrap.sh,v 1.1 2020/08/21 19:50:22 bsiegert Exp $

--- misc/ios/clangwrap.sh.orig	2020-07-24 17:06:50.000000000 +0000
+++ misc/ios/clangwrap.sh
@@ -8,7 +8,7 @@ export IPHONEOS_DEPLOYMENT_TARGET=5.1
 # cmd/cgo doesn't support llvm-gcc-4.2, so we have to use clang.
 CLANG=`xcrun --sdk $SDK --find clang`
 
-if [ "$GOARCH" == "arm64" ]; then
+if [ "$GOARCH" = "arm64" ]; then
 	CLANGARCH="arm64"
 else
 	echo "unknown GOARCH=$GOARCH" >&2
