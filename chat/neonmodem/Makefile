# $NetBSD: Makefile,v 1.5 2024/06/01 14:20:21 pin Exp $

DISTNAME=	neonmodem-1.0.5
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=mrusme/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://neonmodem.com/
COMMENT=	Neon modem overdrive
LICENSE=	gnu-gpl-v3

DEPENDS+=	xdg-utils-[0-9]*:../../misc/xdg-utils

INSTALLATION_DIRS=	bin share/doc/neonmodem
USE_TOOLS+=		itstool gdbus-codegen perl

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/neonmodem \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README.md \
		${DESTDIR}${PREFIX}/share/doc/neonmodem

.include "go-modules.mk"
.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
