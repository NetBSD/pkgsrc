# $NetBSD: Makefile,v 1.2 1998/11/05 18:22:06 garbled Exp $
# FreeBSD Id: Makefile,v 1.3 1998/08/05 09:31:04 asami Exp
#

DISTNAME=	xworm102
PKGNAME=	xworm-1.02
CATEGORIES=	games x11
MASTER_SITES=	http://www.ekran.no/archive/x/

MAINTAINER=	root@garbled.net

ALL_TARGET=	freebsd
USE_X11=	yes
WRKSRC=		${WRKDIR}/XWorm

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/xworm ${PREFIX}/bin
	@ ${MKDIR} ${PREFIX}/share/xworm
.for file in font grid raw
	# ${INSTALL_DATA} ${WRKSRC}/xworm.${file} ${PREFIX}/share/xworm
.endfor

.include "../../mk/bsd.port.mk"
