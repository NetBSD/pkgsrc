$NetBSD: patch-src_icon.sh,v 1.1 2015/08/15 17:48:10 khorben Exp $

Fix generating DeforaOS.png

--- src/icon.sh.orig	2015-08-11 00:24:52.000000000 +0000
+++ src/icon.sh
@@ -115,6 +115,6 @@ while [ $# -gt 0 ]; do
 	#create
 	$DEBUG $CONVERT -background none -density 300 \
 		"../data/DeforaOS-d-${BGCOLOR}.svg" \
-		-resize "$size" $@ \
+		-resize "96x96" $@ \
 		"$OBJDIR$target"				|| return 2
 done
