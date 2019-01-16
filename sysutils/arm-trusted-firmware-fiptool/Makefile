# $NetBSD: Makefile,v 1.1 2019/01/16 14:34:04 martin Exp $

VERSION=	v2.0
GITHUB_PROJECT=	arm-trusted-firmware
# GITHUB_TAG=	?

PKGNAME=	${GITHUB_PROJECT}-fiptool-${VERSION}
DISTNAME=	${PKGNAME}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=ARM-software/}
EXTRACT_SUFX=	.zip

MAINTAINER=	port-arm@NetBSD.org
HOMEPAGE=	https://github.com/ARM-software/arm-trusted-firmware/
COMMENT=	ARM Trusted Firmware fiptool
LICENSE=	modified-bsd

USE_TOOLS+=	gmake
WRKSRC=		${WRKDIR}/${DISTNAME:S:-fiptool-v:-:}/tools/fiptool
	
do-install:
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/fiptool ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
