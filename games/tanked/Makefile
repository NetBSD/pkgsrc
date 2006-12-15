# $NetBSD: Makefile,v 1.14 2006/12/15 20:32:56 joerg Exp $
#

DISTNAME=		tanked-0.90
PKGREVISION=		2
CATEGORIES=		games x11
MASTER_SITES=		# empty

MAINTAINER=		root@garbled.net
#HOMEPAGE=		http://ogresoft.dyn.ml.org/tanked.html
COMMENT=		Multiplayer internet tank game for X11

USE_TOOLS=		imake
SETGIDGAME=		yes

post-patch:
	@${TOUCH} ${WRKSRC}/client/tanked.man
	@${MV} ${WRKSRC}/server/maps.list ${WRKSRC}/server/maps.list.bak
	@${SED} -e 's@XXX@${PREFIX}/share/tanked/@' \
		< ${WRKSRC}/server/maps.list.bak > ${WRKSRC}/server/maps.list

.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
