# $NetBSD: Makefile,v 1.1 2021/03/06 20:16:28 jmcneill Exp $

GITHUB_PROJECT=	linux-m1
GITHUB_TAG=	777de308c5d5f39d12b37c09b8a0d640fc1969e3
DISTNAME=	linux-m1-777de308c5d5f39d12b37c09b8a0d640fc1969e3
PKGNAME=	dtb-arm64-apple-m1-5.11rc4
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=corellium/}
DIST_SUBDIR=	${GITHUB_PROJECT}
EXTRACT_SUFX=	.tar.gz
EXTRACT_ELEMENTS= \
	${GITHUB_PROJECT}-${GITHUB_TAG}/arch/arm64/boot/dts \
	${GITHUB_PROJECT}-${GITHUB_TAG}/include

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/corellium/linux-m1/
COMMENT=	DTB files for arm64 apple-m1 based boards
LICENSE=	gnu-gpl-v2

DTC=		${LOCALBASE}/bin/dtc
DTS_DIR=	${WRKSRC}/arch/arm64/boot/dts
DTS_INC=	${WRKSRC}/include
DTS_ARCH_INC=	${DTS_DIR}/include

DTB_DTS=	apple/apple-m1-j274.dts

do-build:
.for d in ${DTB_DTS}
	cd ${DTS_DIR} && \
	    ${CPP} -P -x assembler-with-cpp -I ${DTS_INC} -I ${DTS_ARCH_INC} \
	        -include ${DTS_DIR}/${d} /dev/null | \
	        ${DTC} -i ${DTS_INC} -i ${DTS_ARCH_INC} -I dts -O dtb \
	            -p 1024 -b 0 -o ${DTS_DIR}/${d:C/dts$/dtb/}
.endfor

do-install:
.for d in ${DTB_DTS}
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/dtb/arm64/apple
	${INSTALL_DATA} ${DTS_DIR}/${d:C/dts$/dtb/} \
	    ${DESTDIR}${PREFIX}/share/dtb/arm64/apple/
.endfor

BUILD_DEPENDS+=	dtc>=1.4.2:../../sysutils/dtc

.include "../../mk/bsd.pkg.mk"
