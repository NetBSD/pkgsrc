# $NetBSD: linux-dtb.mk,v 1.2 2017/05/31 13:24:31 jmcneill Exp $

LK_VERSION=	4.11.3
PKGNAME=	dtb-${DTB_ARCH}-${DTB_DEVICE}-${LK_VERSION}
DISTNAME=	linux-${LK_VERSION}
CATEGORIES=	sysutils
MASTER_SITES=	https://cdn.kernel.org/pub/linux/kernel/v4.x/
EXTRACT_SUFX=	.tar.xz
EXTRACT_ELEMENTS= \
		linux-${LK_VERSION}/arch/${DTB_ARCH}/boot/dts \
		linux-${LK_VERSION}/include

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.kernel.org/
COMMENT=	DTB files for ${DTB_ARCH} ${DTB_DEVICE} based boards
LICENSE=	gnu-gpl-v2

DISTINFO_FILE=	${.CURDIR}/../../sysutils/dtc/linux-distinfo

GENERATE_PLIST=	cd ${DESTDIR}${PREFIX};
GENERATE_PLIST+=${FIND} * -type f | ${SORT};

DTC=		${LOCALBASE}/bin/dtc
DTS_DIR=	${WRKSRC}/arch/${DTB_ARCH}/boot/dts
DTS_INC=	${WRKSRC}/include
DTS_ARCH_INC=	${DTS_DIR}/include

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
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/dtb/${DTB_ARCH}
	${INSTALL_DATA} ${DTS_DIR}/${d:C/dts$/dtb/} \
	    ${DESTDIR}${PREFIX}/share/dtb/${DTB_ARCH}
.endfor

BUILD_DEPENDS+=	dtc>=1.4.2:../../sysutils/dtc
