# $NetBSD: Makefile,v 1.20 2003/09/17 07:15:32 wiz Exp $

PKGNAME=	darcnes-20010401
PKGREVISION=	1

MAINTAINER=	wiz@NetBSD.org
COMMENT=	Multi-system emulator (NES, SMS, GG, PCE, and others)

USE_X11=	yes
MAKE_ENV+=	TARGET=Linux_X

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/darcnes ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/darcnes
	${INSTALL_MAN} ${WRKSRC}/readme ${PREFIX}/share/doc/darcnes

.include "Makefile.common"
.include "../../mk/bsd.pkg.mk"
