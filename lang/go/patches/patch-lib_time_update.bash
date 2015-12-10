$NetBSD: patch-lib_time_update.bash,v 1.1 2015/12/10 20:04:54 bsiegert Exp $

--- lib/time/update.bash.orig	2015-12-03 00:52:58.000000000 +0000
+++ lib/time/update.bash
@@ -41,7 +41,7 @@ zip -0 -r ../../zoneinfo.zip *
 cd ../..
 
 echo
-if [ "$1" == "-work" ]; then 
+if [ "$1" = "-work" ]; then 
 	echo Left workspace behind in work/.
 else
 	rm -rf work


