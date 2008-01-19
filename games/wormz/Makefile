# $NetBSD: Makefile,v 1.20 2008/01/19 09:16:22 wiz Exp $
#

DISTNAME=		Wormz-1.0b5
PKGNAME=		wormz-1.0b5
PKGREVISION=		1
CATEGORIES=		games x11
MASTER_SITES=		http://lide.punknet.cz/miri/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://lide.punknet.cz/miri/Wormz.html
COMMENT=		Networked game for X11

WRKSRC=			${WRKDIR}/Wormz
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake

post-extract:
	${MKDIR} ${WRKSRC}/NetBSD
	${TOUCH} ${WRKSRC}/NetBSD/.depend
	${MKDIR} ${WRKSRC}/DragonFly
	${TOUCH} ${WRKSRC}/DragonFly/.depend

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} depend

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
