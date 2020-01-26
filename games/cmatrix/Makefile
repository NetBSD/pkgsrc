# $NetBSD: Makefile,v 1.14 2020/01/26 17:31:13 rillig Exp $

DISTNAME=		cmatrix-1.2a
PKGREVISION=		2
CATEGORIES=		games
MASTER_SITES=		http://www.asty.org/cmatrix/dist/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.asty.org/cmatrix/
COMMENT=		Simulates the display from "The Matrix" in your console

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cmatrix ${DESTDIR}${PREFIX}/bin/cmatrix
	${INSTALL_MAN} ${WRKSRC}/cmatrix.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/cmatrix.1
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/cmatrix
	${INSTALL_DATA} ${WRKSRC}/mtx.pcf \
		${DESTDIR}${PREFIX}/share/cmatrix/mtx.pcf

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
