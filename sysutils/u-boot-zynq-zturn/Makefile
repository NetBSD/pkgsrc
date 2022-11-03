# $NetBSD: Makefile,v 1.1 2022/11/03 10:56:49 jmcneill Exp $

UBOOT_TARGET=		zynq-zturn
UBOOT_VERSION=		2022.10
UBOOT_ENV+=		DEVICE_TREE=zynq-zturn
UBOOT_CONFIG=		xilinx_zynq_virt_defconfig
UBOOT_BIN=		u-boot.img spl/boot.bin

.include "../../sysutils/u-boot/u-boot-arm.mk"
.include "../../mk/bsd.pkg.mk"
