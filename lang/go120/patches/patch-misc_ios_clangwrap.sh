$NetBSD: patch-misc_ios_clangwrap.sh,v 1.1 2023/02/05 13:25:26 bsiegert Exp $

--- misc/ios/clangwrap.sh.orig	2020-12-17 16:09:06.000000000 +0000
+++ misc/ios/clangwrap.sh
@@ -2,7 +2,7 @@
 # This uses the latest available iOS SDK, which is recommended.
 # To select a specific SDK, run 'xcodebuild -showsdks'
 # to see the available SDKs and replace iphoneos with one of them.
-if [ "$GOARCH" == "arm64" ]; then
+if [ "$GOARCH" = "arm64" ]; then
 	SDK=iphoneos
 	PLATFORM=ios
 	CLANGARCH="arm64"
