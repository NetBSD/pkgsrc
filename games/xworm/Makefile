# $NetBSD: Makefile,v 1.16 2007/02/02 01:08:01 joerg Exp $

DISTNAME=	xworm102
PKGNAME=	xworm-1.02
PKGREVISION=	1
CATEGORIES=	games x11
MASTER_SITES=	http://www.ekran.no/archive/x/

MAINTAINER=	root@garbled.net
COMMENT=	Classic game with apples and hungry worm

WRKSRC=		${WRKDIR}/XWorm
BUILD_TARGET=	bsd

INSTALLATION_DIRS=	bin

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/xworm ${PREFIX}/bin
	@ ${INSTALL_DATA_DIR} ${PREFIX}/share/xworm
.for file in font grid raw
	${INSTALL_DATA} ${WRKSRC}/xworm.${file} ${PREFIX}/share/xworm
.endfor

.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
