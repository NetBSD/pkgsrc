# $NetBSD: Makefile,v 1.3 1999/01/30 23:18:48 agc Exp $
#

DISTNAME=		tanked-0.90
CATEGORIES=		games x11
MASTER_SITES=		http://ogresoft.dyn.ml.org/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://ogresoft.dyn.ml.org/tanked.html

DEPENDS+=		xpm-3.4k:../../graphics/xpm

USE_X11BASE=		yes

post-patch:
	@${TOUCH} ${WRKSRC}/client/tanked.man
	@${MV} ${WRKSRC}/server/maps.list ${WRKSRC}/server/maps.list.bak
	@${SED} -e 's@XXX@${X11BASE}/share/tanked/@' \
		< ${WRKSRC}/server/maps.list.bak > ${WRKSRC}/server/maps.list

.include "../../mk/bsd.pkg.mk"
