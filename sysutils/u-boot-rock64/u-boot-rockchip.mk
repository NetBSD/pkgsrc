#	$NetBSD: u-boot-rockchip.mk,v 1.1 2020/04/02 09:09:05 tnn Exp $
#
# used by sysutils/u-boot-rock64/Makefile

# Common makefile fragment for rockchip based u-boot targets.
#
# Set these variables:
#
#	U_BOOT_IMAGE_TYPE	("rk3399", "rk3328")
#

UBOOT_VERSION=	${GITHUB_TAG:C/-.*$//}
MASTER_SITES=	${MASTER_SITE_GITHUB:=ayufan-rock64/}
GITHUB_PROJECT=	linux-u-boot
GITHUB_TAG=	2017.09-rockchip-ayufan-1063-g29843fbd42
DISTNAME=	${GITHUB_TAG}
PATCHDIR=	${.CURDIR}/../../sysutils/u-boot-rockpro64/patches
DISTFILES=	${DEFAULT_DISTFILES}
EXTRACT_SUFX=	.tar.gz

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
	${WRKSRC}/tools/mkimage -n ${U_BOOT_IMAGE_TYPE} -T rksd -d ${WRKDIR}/${DDR_BIN} ${WRKSRC}/idbloader.img
# append stage2 loader
	cat ${WRKSRC}/spl/u-boot-spl.bin >> ${WRKSRC}/idbloader.img
# wrap everything up into a single file that can be written to an SD card
	cp ${WRKSRC}/idbloader.img ${WRKSRC}/rksd_loader.img
	dd if=${WRKSRC}/u-boot.itb seek=448 conv=notrunc of=${WRKSRC}/rksd_loader.img
# build SPI NOR flash image. See dev-ayufan/build.mk.
	set -e; b=0; while [ "$$b" != 128 ]; do dd bs=2k count=1; dd if=/dev/zero bs=2k count=1; b=$$(expr $$b + 1); done < ${WRKSRC}/idbloader.img > ${WRKSRC}/rkspi_loader.img 2> /dev/null
	dd if=${WRKSRC}/u-boot.itb seek=1024 conv=notrunc of=${WRKSRC}/rkspi_loader.img
