$NetBSD: patch-misc_ios_clangwrap.sh,v 1.1 2024/08/14 10:04:04 bsiegert Exp $

--- misc/ios/clangwrap.sh.orig	2024-06-20 19:20:56.000000000 +0000
+++ misc/ios/clangwrap.sh
@@ -9,7 +9,7 @@
 SDK=iphonesimulator
 PLATFORM=ios-simulator
 
-if [ "$GOARCH" == "arm64" ]; then
+if [ "$GOARCH" = "arm64" ]; then
 	CLANGARCH="arm64"
 else
 	CLANGARCH="x86_64"
