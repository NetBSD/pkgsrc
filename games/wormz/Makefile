# $NetBSD: Makefile,v 1.17 2006/05/12 06:45:01 joerg Exp $
#

DISTNAME=		Wormz-1.0b5
PKGNAME=		wormz-1.0b5
PKGREVISION=		1
CATEGORIES=		games x11
MASTER_SITES=		http://lide.punknet.cz/miri/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://lide.punknet.cz/miri/wormz.html
COMMENT=		Networked game for X11

WRKSRC=			${WRKDIR}/Wormz
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake

.include "../../mk/x11.buildlink3.mk"

post-extract:
	${MKDIR} ${WRKSRC}/NetBSD
	${TOUCH} ${WRKSRC}/NetBSD/.depend
	${MKDIR} ${WRKSRC}/DragonFly
	${TOUCH} ${WRKSRC}/DragonFly/.depend

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} depend

.include "../../mk/bsd.pkg.mk"
