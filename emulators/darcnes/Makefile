# $NetBSD: Makefile,v 1.25 2007/06/17 07:42:47 wiz Exp $

PKGNAME=	darcnes-20010401
PKGREVISION=	3

MAINTAINER=	wiz@NetBSD.org
COMMENT=	Multi-system emulator (NES, SMS, GG, PCE, and others)

MAKE_ENV+=	TARGET=Linux_X

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/darcnes ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/darcnes
	${INSTALL_MAN} ${WRKSRC}/readme ${PREFIX}/share/doc/darcnes

.include "Makefile.common"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
