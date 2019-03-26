$NetBSD: patch-sys_ios-sdk.sh,v 1.2 2019/03/26 19:29:53 ryoon Exp $

* POSIX shell portability

--- sys/ios-sdk.sh.orig	2019-02-19 12:35:24.000000000 +0000
+++ sys/ios-sdk.sh
@@ -152,7 +152,7 @@ while test $# -gt 0; do
 	-archs|-a|--archs)
 		shift
 		if test $# -gt 0; then
-			if [ "$1" == "all" ]; then
+			if [ "$1" = "all" ]; then
 				ARCHS="armv7+armv7s+arm64"
 			else
 				ARCHS=$1
