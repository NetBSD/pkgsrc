# $NetBSD: Makefile,v 1.22 2005/06/16 06:57:50 jlam Exp $

PKGNAME=	darcnes-20010401
PKGREVISION=	1

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
