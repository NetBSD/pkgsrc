# $NetBSD: Makefile,v 1.2 2018/09/01 12:04:56 tnn Exp $

UBOOT_TARGET=		rockpro64
UBOOT_CONFIG=		rockpro64-rk3399_defconfig
UBOOT_BIN=		idbloader.img rksd_loader.img u-boot.itb

PKGREVISION=	1
UBOOT_VERSION=	${GITHUB_TAG:C/-.*$//}
MASTER_SITES=	${MASTER_SITE_GITHUB:=ayufan-rock64/}
GITHUB_PROJECT=	linux-u-boot
GITHUB_TAG=	2017.09-rockchip-ayufan-1033-gdf02018479
DISTNAME=	${GITHUB_TAG}
DISTINFO_FILE=	${.CURDIR}/../../sysutils/u-boot-rockpro64/distinfo
PATCHDIR=	${.CURDIR}/../../sysutils/u-boot-rockpro64/patches
DISTFILES=	${DEFAULT_DISTFILES}
EXTRACT_SUFX=	.tar.gz

# Boot Loader stage 3-1 (BL31) EL3 Runtime Firmware
# XXX LICENSE?
BL31=		rk3399_bl31_v1.18.elf
DISTFILES+=	${BL31}
SITES.${BL31}=	${MASTER_SITE_GITHUB:=rockchip-linux/rkbin/raw/9e6625e7551ffa591f0ac4c271f12a7ab5cedcf4/bin/rk33/}

# DDR init binary
DDR_BIN=		rk3399_ddr_800MHz_v1.14.bin
SITES.${DDR_BIN}=	${MASTER_SITE_GITHUB:=rockchip-linux/rkbin/raw/dbc8710a93406669fb2df2d57dc086228bf1979f/bin/rk33/}
DISTFILES+=		${DDR_BIN}

# pkgsrc tries to run distfiles that end in .bin; handle manually
EXTRACT_ONLY=	${DISTFILES:N*.bin}

USE_TOOLS+=	gawk
MAKE_ENV+=	BL31=${WRKDIR}/${BL31}

post-extract:
	cp ${DISTDIR}/${DDR_BIN} ${WRKDIR}

post-build:
# build stage 3 package
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} u-boot.itb
# build stage 1 loader
	${WRKSRC}/tools/mkimage -n rk3399 -T rksd -d ${WRKDIR}/${DDR_BIN} ${WRKSRC}/idbloader.img
# append stage2 loader
	cat ${WRKSRC}/spl/u-boot-spl.bin >> ${WRKSRC}/idbloader.img
# wrap everything up into a single file that can be written to an SD card
	cp ${WRKSRC}/idbloader.img ${WRKSRC}/rksd_loader.img
	dd if=${WRKSRC}/u-boot.itb seek=448 conv=notrunc of=${WRKSRC}/rksd_loader.img

.include "../../sysutils/u-boot/u-boot-arm64.mk"
