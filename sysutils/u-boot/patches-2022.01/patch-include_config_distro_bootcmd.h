$NetBSD: patch-include_config_distro_bootcmd.h,v 1.1 2022/02/11 21:46:14 mrg Exp $

Fix bug in BOOTENV_SET_SCSI_NEED_INIT that skips the SCSI scan.
Probably fix virtio as well.

--- include/config_distro_bootcmd.h.orig	2022-01-10 10:46:34.000000000 -0800
+++ include/config_distro_bootcmd.h	2022-02-09 01:21:58.541415139 -0800
@@ -217,11 +217,11 @@
 
 #ifdef CONFIG_SCSI
 #define BOOTENV_RUN_SCSI_INIT "run scsi_init; "
-#define BOOTENV_SET_SCSI_NEED_INIT "scsi_need_init=; "
+#define BOOTENV_SET_SCSI_NEED_INIT "setenv scsi_need_init; "
 #define BOOTENV_SHARED_SCSI \
 	"scsi_init=" \
 		"if ${scsi_need_init}; then " \
-			"scsi_need_init=false; " \
+			"setenv scsi_need_init false; " \
 			"scsi scan; " \
 		"fi\0" \
 	\
@@ -295,11 +295,11 @@
 
 #ifdef CONFIG_CMD_VIRTIO
 #define BOOTENV_RUN_VIRTIO_INIT "run virtio_init; "
-#define BOOTENV_SET_VIRTIO_NEED_INIT "virtio_need_init=; "
+#define BOOTENV_SET_VIRTIO_NEED_INIT "setenv virtio_need_init; "
 #define BOOTENV_SHARED_VIRTIO \
 	"virtio_init=" \
 		"if ${virtio_need_init}; then " \
-			"virtio_need_init=false; " \
+			"setenv virtio_need_init false; " \
 			"virtio scan; " \
 		"fi\0" \
 	\
