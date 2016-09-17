$NetBSD: patch-lib_time_update.bash,v 1.3 2016/09/17 15:56:58 bsiegert Exp $

--- lib/time/update.bash.orig	2016-09-07 19:34:33.000000000 +0000
+++ lib/time/update.bash
@@ -42,7 +42,7 @@ zip -0 -r ../../zoneinfo.zip *
 cd ../..
 
 echo
-if [ "$1" == "-work" ]; then 
+if [ "$1" = "-work" ]; then 
 	echo Left workspace behind in work/.
 else
 	rm -rf work
