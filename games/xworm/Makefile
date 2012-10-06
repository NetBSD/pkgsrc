# $NetBSD: Makefile,v 1.19 2012/10/06 11:55:04 asau Exp $

DISTNAME=	xworm102
PKGNAME=	xworm-1.02
PKGREVISION=	1
CATEGORIES=	games x11
MASTER_SITES=	http://www.ekran.no/archive/x/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Classic game with apples and hungry worm

WRKSRC=		${WRKDIR}/XWorm
BUILD_TARGET=	bsd

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xworm ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/xworm
.for file in font grid raw
	${INSTALL_DATA} ${WRKSRC}/xworm.${file} ${DESTDIR}${PREFIX}/share/xworm
.endfor

.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
