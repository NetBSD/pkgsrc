$NetBSD: patch-roms_u-boot_tools_imx8m__image.sh,v 1.1 2021/02/20 22:55:19 ryoon Exp $

* Improve POSIX shell portability

--- roms/u-boot/tools/imx8m_image.sh.orig	2019-04-23 18:16:46.000000000 +0000
+++ roms/u-boot/tools/imx8m_image.sh
@@ -12,7 +12,7 @@ blobs=`awk '/^SIGNED_HDMI/ {print $2} /^
 for f in $blobs; do
 	tmp=$srctree/$f
 
-	if [ $f == "spl/u-boot-spl-ddr.bin" ] || [ $f == "u-boot.itb" ]; then
+	if [ $f = "spl/u-boot-spl-ddr.bin" ] || [ $f = "u-boot.itb" ]; then
 		continue
 	fi
 
@@ -28,7 +28,7 @@ for f in $blobs; do
 	sed -in "s;$f;$tmp;" $file
 done
 
-if [ $post_process == 1 ]; then
+if [ $post_process = 1 ]; then
 	if [ -f $srctree/lpddr4_pmu_train_1d_imem.bin ]; then
 		objcopy -I binary -O binary --pad-to 0x8000 --gap-fill=0x0 $srctree/lpddr4_pmu_train_1d_imem.bin lpddr4_pmu_train_1d_imem_pad.bin
 		objcopy -I binary -O binary --pad-to 0x4000 --gap-fill=0x0 $srctree/lpddr4_pmu_train_1d_dmem.bin lpddr4_pmu_train_1d_dmem_pad.bin
