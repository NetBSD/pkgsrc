# $NetBSD: Makefile,v 1.10 2005/06/12 08:22:59 jlam Exp $
#

DISTNAME=		tanked-0.90
CATEGORIES=		games x11
MASTER_SITES=		# empty

MAINTAINER=		root@garbled.net
#HOMEPAGE=		http://ogresoft.dyn.ml.org/tanked.html
COMMENT=		Multiplayer internet tank game for X11

USE_X11BASE=		YES
USE_TOOLS+=		imake

post-patch:
	@${TOUCH} ${WRKSRC}/client/tanked.man
	@${MV} ${WRKSRC}/server/maps.list ${WRKSRC}/server/maps.list.bak
	@${SED} -e 's@XXX@${X11PREFIX}/share/tanked/@' \
		< ${WRKSRC}/server/maps.list.bak > ${WRKSRC}/server/maps.list

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
