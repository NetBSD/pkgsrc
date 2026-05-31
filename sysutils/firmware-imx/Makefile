# $NetBSD: Makefile,v 1.1 2026/05/31 13:26:22 rxg Exp $

DISTNAME=	firmware-imx-8.31-4fa5b46.bin
PKGNAME=	${DISTNAME:C/-[^-]*\.bin$//}
CATEGORIES=	sysutils
MASTER_SITES=	https://www.nxp.com/lgfiles/NMG/MAD/YOCTO/
EXTRACT_SUFX=	# empty

MAINTAINER=	port-arm@NetBSD.org
HOMEPAGE=	https://www.nxp.com/
COMMENT=	Firmware binary blobs for NXP i.MX SoCs
LICENSE=	firmware-imx-license

RESTRICTED=		Redistribution not permitted
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}

WRKSRC=		${WRKDIR}/${DISTNAME:R}/firmware
USE_TOOLS=	pax
NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS=	libdata/firmware/imx

do-extract:
	${CP} ${DISTDIR}/${DISTFILES} ${WRKDIR}
	${CHMOD} a+x ${WRKDIR}/${DISTNAME}
	cd ${WRKDIR} && ${SH} ${DISTNAME} --auto-accept

do-install:
	cd ${WRKSRC} && pax -rw . ${DESTDIR}${PREFIX}/libdata/firmware/imx

.include "../../mk/bsd.pkg.mk"
