# $NetBSD: Makefile,v 1.9 2003/03/29 12:41:12 jmmv Exp $
# FreeBSD Id: Makefile,v 1.3 1998/08/05 09:31:04 asami Exp
#

DISTNAME=	xworm102
PKGNAME=	xworm-1.02
WRKSRC=		${WRKDIR}/XWorm
CATEGORIES=	games x11
MASTER_SITES=	http://www.ekran.no/archive/x/

MAINTAINER=	root@garbled.net
COMMENT=	Classic game with apples and hungry worm

ALL_TARGET=	bsd
USE_X11=	yes

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/xworm ${PREFIX}/bin
	@ ${INSTALL_DATA_DIR} ${PREFIX}/share/xworm
.for file in font grid raw
	${INSTALL_DATA} ${WRKSRC}/xworm.${file} ${PREFIX}/share/xworm
.endfor

.include "../../mk/bsd.pkg.mk"
