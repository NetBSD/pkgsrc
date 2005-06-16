# $NetBSD: Makefile,v 1.14 2005/06/16 06:57:56 jlam Exp $

DISTNAME=	xworm102
PKGNAME=	xworm-1.02
CATEGORIES=	games x11
MASTER_SITES=	http://www.ekran.no/archive/x/

MAINTAINER=	root@garbled.net
COMMENT=	Classic game with apples and hungry worm

WRKSRC=		${WRKDIR}/XWorm
BUILD_TARGET=	bsd

INSTALLATION_DIRS=	bin

.include "../../mk/x11.buildlink3.mk"

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/xworm ${PREFIX}/bin
	@ ${INSTALL_DATA_DIR} ${PREFIX}/share/xworm
.for file in font grid raw
	${INSTALL_DATA} ${WRKSRC}/xworm.${file} ${PREFIX}/share/xworm
.endfor

.include "../../mk/bsd.pkg.mk"
