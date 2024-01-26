# $NetBSD: Makefile,v 1.22 2024/01/26 12:58:05 wiz Exp $

DISTNAME=	mbrola-3.3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=numediart/}
GITHUB_PROJECT=	MBROLA
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/numediart/MBROLA/
COMMENT=	Speech synthesizer
LICENSE=	gnu-agpl-v3

WRKSRC=		${WRKDIR}/MBROLA-3.3

USE_TOOLS+=	gmake pax
BUILD_TARGET=

INSTALLATION_DIRS=	bin share/doc/mbrola

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Bin/mbrola ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC}/Documentation && pax -pp -rw * ${DESTDIR}${PREFIX}/share/doc/mbrola

.include "../../mk/bsd.pkg.mk"
