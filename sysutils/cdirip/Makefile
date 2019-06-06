# $NetBSD: Makefile,v 1.1 2019/06/06 08:33:49 tpaul Exp $

DISTNAME=	cdirip-0.6.4
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=jozip/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	tpaul@NetBSD.org
HOMEPAGE=	https://github.com/jozip/cdirip/
COMMENT=	Program for extracting tracks from a CDI (DiscJuggler) image
LICENSE=	gnu-gpl-v2

MAKE_FLAGS+=	CC=${CC:Q}

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cdirip ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
