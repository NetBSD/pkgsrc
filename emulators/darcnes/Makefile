# $NetBSD: Makefile,v 1.23 2006/02/05 23:09:00 joerg Exp $

PKGNAME=	darcnes-20010401
PKGREVISION=	2

MAINTAINER=	wiz@NetBSD.org
COMMENT=	Multi-system emulator (NES, SMS, GG, PCE, and others)

MAKE_ENV+=	TARGET=Linux_X

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/darcnes ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/darcnes
	${INSTALL_MAN} ${WRKSRC}/readme ${PREFIX}/share/doc/darcnes

.include "Makefile.common"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
