# $NetBSD: Makefile,v 1.3 2022/03/03 10:41:00 nia Exp $

DISTNAME=	hexd-1.1.0
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=FireyFly/}
GITHUB_PROJECT=	hexd
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/FireyFly/hexd
COMMENT=	Colourful, human-friendly hexdump tool for reverse engineering
LICENSE=	mit

USE_TOOLS+=	gmake

BUILD_TARGET=	hexd

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hexd ${DESTDIR}${PREFIX}/bin/hexd
	${INSTALL_DATA} ${WRKSRC}/hexd.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/hexd.1

.include "../../mk/bsd.pkg.mk"
