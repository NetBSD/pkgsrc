# $NetBSD: Makefile,v 1.3 1999/01/30 23:18:47 agc Exp $
#

DISTNAME=	golddig2
PKGNAME=	golddig-2.0
CATEGORIES=	games x11
MASTER_SITES=	ftp://uiarchive.cso.uiuc.edu/pub/systems/linux/sunsite/games/arcade/

MAINTAINER=	root@garbled.net

USE_X11BASE=	yes

post-extract:
	${RM} ${WRKSRC}/golddig ${WRKSRC}/makelev ${WRKSRC}/*.o

.include "../../mk/bsd.pkg.mk"
