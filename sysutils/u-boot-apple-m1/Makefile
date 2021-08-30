# $NetBSD: Makefile,v 1.6 2021/08/30 23:44:39 jmcneill Exp $

UBOOT_TARGET=		apple-m1
UBOOT_CONFIG=		apple_m1_defconfig
UBOOT_BIN=		u-boot-nodtb.bin u-boot.macho

DISTINFO_FILE?=		${.CURDIR}/../../sysutils/u-boot-apple-m1/distinfo
PATCHDIR?=		${.CURDIR}/../../sysutils/u-boot-apple-m1/patches

UBOOT_VERSION=  2021.04rc3
GITHUB_PROJECT=	u-boot
GITHUB_TAG=	8e7191541ca9b4cda9ee191b2728cf29f1660bdd
MASTER_SITES=   ${MASTER_SITE_GITHUB:=kettenis/}
DIST_SUBDIR=	${GITHUB_PROJECT}
DISTNAME=	u-boot-apple-m1-${GITHUB_TAG}
EXTRACT_SUFX=	.tar.gz
PKGNAME=	u-boot-apple-m1-${UBOOT_VERSION}
BUILD_TARGET=	u-boot-nodtb.bin

USE_TOOLS+=	gzip

BUILD_DEPENDS+=	m1n1>=0:../../sysutils/m1n1
BUILD_DEPENDS+=	dtc>=0:../../sysutils/dtc

DTS_DIR=	${WRKSRC}/arch/arm/dts
DTS_INC=	${WRKSRC}/include
DTS_ARCH_INC=	${DTS_DIR}/include

post-build:
	cd ${DTS_DIR} && \
	    ${CPP} -P -x assembler-with-cpp -I ${DTS_INC} -I ${DTS_ARCH_INC} \
	    -include ${DTS_DIR}/t8103-j274.dts /dev/null | \
	    ${PREFIX}/bin/dtc -i ${DTS_INC} -i ${DTS_ARCH_INC} -I dts -O dtb \
	       -p 1024 -b 0 -o ${WRKDIR}/t8103-j274.dtb
	cp ${WRKSRC}/u-boot-nodtb.bin ${WRKDIR}
	rm -f ${WRKDIR}/u-boot-nodtb.bin.gz && gzip ${WRKDIR}/u-boot-nodtb.bin
	cat ${PREFIX}/share/m1n1/m1n1.macho \
	    ${WRKDIR}/u-boot-nodtb.bin.gz \
	    ${WRKDIR}/t8103-j274.dtb \
	    > ${WRKSRC}/u-boot.macho

.include "../../sysutils/u-boot/u-boot-arm64.mk"
.include "../../mk/bsd.pkg.mk"
