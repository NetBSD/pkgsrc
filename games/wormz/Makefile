# $NetBSD: Makefile,v 1.4 2000/08/26 02:22:47 wiz Exp $
#

DISTNAME=		Wormz-1.0b5
PKGNAME=		wormz-1.0b5
CATEGORIES=		games x11
MASTER_SITES=		http://lide.punknet.cz/miri/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://lide.punknet.cz/miri/wormz.html

WRKSRC=			${WRKDIR}/Wormz
USE_GMAKE=		yes
USE_X11BASE=		yes

post-extract:
	${MKDIR} ${WRKSRC}/NetBSD
	${TOUCH} ${WRKSRC}/NetBSD/.depend

do-configure:
	(cd ${WRKSRC} && ${GMAKE} ${MAKE_ENV} depend)

.include "../../mk/bsd.pkg.mk"
