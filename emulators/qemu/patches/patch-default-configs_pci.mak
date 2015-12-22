$NetBSD: patch-default-configs_pci.mak,v 1.1.2.2 2015/12/22 20:21:43 bsiegert Exp $

--- default-configs/pci.mak.orig	2015-12-16 22:04:48.000000000 +0000
+++ default-configs/pci.mak
@@ -35,5 +35,5 @@ CONFIG_SDHCI=y
 CONFIG_EDU=y
 CONFIG_VGA=y
 CONFIG_VGA_PCI=y
-CONFIG_IVSHMEM=$(CONFIG_POSIX)
+CONFIG_IVSHMEM=$(CONFIG_SHM_OPEN)
 CONFIG_ROCKER=y
