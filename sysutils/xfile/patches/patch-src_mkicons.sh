$NetBSD: patch-src_mkicons.sh,v 1.1 2025/01/05 21:38:22 vins Exp $

Point to default sed tool path.

--- src/mkicons.sh.orig	2025-01-05 10:51:11.537448173 +0000
+++ src/mkicons.sh
@@ -22,7 +22,7 @@ printf 'struct xpm_data { char *name; ch
 
 for n in $ICONS; do
 	for s in $SIZES; do
-		cat "icons/$n.$s.xpm" | sed -e 's/_xpm//g' >> $TGT
+		cat "icons/$n.$s.xpm" | @SED@ -e 's/_xpm//g' >> $TGT
 	done
 done
 
