# $NetBSD: Makefile,v 1.5 1998/11/13 22:35:58 hubertf Exp $
#

DISTNAME=		xwave-0.6
WRKSRC=			${WRKDIR}/xwave
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/sound/editors

MAINTAINER=		hubertf@netbsd.org

DEPENDS+=		xpm-*:../../graphics/xpm

USE_IMAKE=		yes

post-patch:
	cd ${WRKSRC} ; ${MV} src/XWave src/XWave.ad
	cd ${WRKSRC} ; ${TOUCH} src/xwave.man

.include "../../mk/bsd.pkg.mk"
