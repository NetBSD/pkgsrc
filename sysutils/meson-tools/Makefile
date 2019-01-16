# $NetBSD: Makefile,v 1.1 2019/01/16 18:33:22 martin Exp $

VERSION=	0.1
GITHUB_PROJECT=	meson-tools
# GITHUB_TAG=	?

DISTNAME=	meson-tools-${VERSION}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=afaerber/}
GITHUB_TAG=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.zip

MAINTAINER=	port-arm@NetBSD.org
HOMEPAGE=	https://github.com/afaerber/meson-tools/
COMMENT=	Firmware packaging tools for the Amlogic Meson family of ARM based SoCs.
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake
	
do-install:
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/amlbootsig ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/amlinfo ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/unamlbootsig ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
