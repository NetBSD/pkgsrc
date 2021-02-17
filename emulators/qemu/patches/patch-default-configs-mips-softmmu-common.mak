$NetBSD: patch-default-configs-mips-softmmu-common.mak,v 1.1 2021/02/17 17:16:01 reinoud Exp $

--- default-configs/mips-softmmu-common.mak.orig	2020-08-11 19:17:14.000000000 +0000
+++ default-configs/mips-softmmu-common.mak
@@ -37,6 +37,7 @@ CONFIG_R4K=y
 CONFIG_MALTA=y
 CONFIG_PCNET_PCI=y
 CONFIG_MIPSSIM=y
+CONFIG_MIPSSIM_VIRTIO=y
 CONFIG_ACPI_SMBUS=y
 CONFIG_SMBUS_EEPROM=y
 CONFIG_TEST_DEVICES=y
