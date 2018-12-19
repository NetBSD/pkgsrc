$NetBSD: patch-tools_imx__cntr__image.sh,v 1.1 2018/12/19 12:03:01 ryoon Exp $

* POSIX shell portablity fix

--- tools/imx_cntr_image.sh.orig	2018-11-14 16:10:06.000000000 +0000
+++ tools/imx_cntr_image.sh
@@ -10,7 +10,7 @@ file=$1
 blobs=`awk '/^APPEND/ {print $2} /^IMAGE/ || /^DATA/ {print $3}' $file`
 for f in $blobs; do
 	tmp=$srctree/$f
-	if [ $f == "u-boot-dtb.bin" ]; then
+	if [ $f = "u-boot-dtb.bin" ]; then
 		continue
 	fi
 
