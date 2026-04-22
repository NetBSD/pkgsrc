# $NetBSD: Makefile,v 1.23.2.1 2026/04/22 14:31:55 maya Exp $

DISTNAME=	neonmodem-1.0.7
PKGREVISION=	9
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=mrusme/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
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
