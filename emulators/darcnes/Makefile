# $NetBSD: Makefile,v 1.27 2008/03/03 19:21:38 jlam Exp $

PKGNAME=	darcnes-20010401
PKGREVISION=	3

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Multi-system emulator (NES, SMS, GG, PCE, and others)

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_ENV+=	TARGET=Linux_X

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/darcnes ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/darcnes
	${INSTALL_MAN} ${WRKSRC}/readme ${DESTDIR}${PREFIX}/share/doc/darcnes

.include "Makefile.common"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
