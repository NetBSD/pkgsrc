#	$NetBSD: u-boot-rockchip.mk,v 1.1 2019/06/08 12:25:05 mrg Exp $

#
# Common makefile fragment for rockchip based u-boot targets.
#
# Set these variables:
#
#	U_BOOT_IMAGE_TYPE	("rk3399", "rk3328")
#

PKGREVISION=	2
UBOOT_VERSION=	${GITHUB_TAG:C/-.*$//}
MASTER_SITES=	${MASTER_SITE_GITHUB:=ayufan-rock64/}
GITHUB_PROJECT=	linux-u-boot
GITHUB_TAG=	2017.09-rockchip-ayufan-1056-ge2de533f6c
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
