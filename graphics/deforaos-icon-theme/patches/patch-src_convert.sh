$NetBSD: patch-src_convert.sh,v 1.3 2016/12/22 11:37:18 joerg Exp $

Specify input format since recent ImageMagick versions won't auto-detect MVG.

--- src/convert.sh.orig	2016-12-22 01:24:35.867340142 +0000
+++ src/convert.sh
@@ -540,7 +540,7 @@ _convert()
 		gravity Center
 		text 0,0 '$char'
 	pop graphic-context
-pop graphic-context" | $DEBUG $CONVERT -background none - \
+pop graphic-context" | $DEBUG $CONVERT -background none mvg:- \
 		-resize "$size" $@ \
 		"$OBJDIR$folder/${stock}.png"			|| return 2
 	done
