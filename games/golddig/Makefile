# $NetBSD: Makefile,v 1.4 2001/02/16 15:10:51 wiz Exp $
#

DISTNAME=	golddig2
PKGNAME=	golddig-2.0
CATEGORIES=	games x11
MASTER_SITES=	ftp://uiarchive.cso.uiuc.edu/pub/systems/linux/sunsite/games/arcade/

MAINTAINER=	root@garbled.net
COMMENT=	Fast action game designed for use with X

USE_X11BASE=	yes

post-extract:
	${RM} ${WRKSRC}/golddig ${WRKSRC}/makelev ${WRKSRC}/*.o

.include "../../mk/bsd.pkg.mk"
