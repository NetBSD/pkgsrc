# $NetBSD: Makefile,v 1.10 2004/01/20 12:15:42 agc Exp $
# FreeBSD Id: Makefile,v 1.3 1998/08/05 09:31:04 asami Exp
#

DISTNAME=	xworm102
PKGNAME=	xworm-1.02
CATEGORIES=	games x11
MASTER_SITES=	http://www.ekran.no/archive/x/

MAINTAINER=	root@garbled.net
COMMENT=	Classic game with apples and hungry worm

WRKSRC=		${WRKDIR}/XWorm
ALL_TARGET=	bsd
USE_X11=	yes

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/xworm ${PREFIX}/bin
	@ ${INSTALL_DATA_DIR} ${PREFIX}/share/xworm
.for file in font grid raw
	${INSTALL_DATA} ${WRKSRC}/xworm.${file} ${PREFIX}/share/xworm
.endfor

.include "../../mk/bsd.pkg.mk"
