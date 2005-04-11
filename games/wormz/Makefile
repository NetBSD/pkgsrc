# $NetBSD: Makefile,v 1.12 2005/04/11 21:45:57 tv Exp $
#

DISTNAME=		Wormz-1.0b5
PKGNAME=		wormz-1.0b5
CATEGORIES=		games x11
MASTER_SITES=		http://lide.punknet.cz/miri/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://lide.punknet.cz/miri/wormz.html
COMMENT=		Networked game for X11

WRKSRC=			${WRKDIR}/Wormz
USE_X11=		yes
USE_GNU_TOOLS+=		make

post-extract:
	${MKDIR} ${WRKSRC}/NetBSD
	${TOUCH} ${WRKSRC}/NetBSD/.depend

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} depend

.include "../../mk/bsd.pkg.mk"
