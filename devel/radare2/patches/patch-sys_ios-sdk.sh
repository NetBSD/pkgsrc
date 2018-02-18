$NetBSD: patch-sys_ios-sdk.sh,v 1.1 2018/02/18 17:40:18 kamil Exp $

--- sys/ios-sdk.sh.orig	2018-01-29 10:36:59.000000000 +0000
+++ sys/ios-sdk.sh
@@ -131,7 +131,7 @@ while test $# -gt 0; do
 		-archs)
 			shift
 			if test $# -gt 0; then
-				if [ "$1" == "all" ]; then
+				if [ "$1" = "all" ]; then
 					ARCHS="armv7+armv7s+arm64"
 				else
 					ARCHS=$1
