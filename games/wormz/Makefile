# $NetBSD: Makefile,v 1.8 2003/03/29 12:41:09 jmmv Exp $
#

DISTNAME=		Wormz-1.0b5
PKGNAME=		wormz-1.0b5
WRKSRC=			${WRKDIR}/Wormz
CATEGORIES=		games x11
MASTER_SITES=		http://lide.punknet.cz/miri/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://lide.punknet.cz/miri/wormz.html
COMMENT=		Networked game for X11

USE_BUILDLINK2=		yes
USE_X11=		yes
USE_GMAKE=		yes

post-extract:
	${MKDIR} ${WRKSRC}/NetBSD
	${TOUCH} ${WRKSRC}/NetBSD/.depend

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} depend

.include "../../mk/bsd.pkg.mk"
