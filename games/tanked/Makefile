# $NetBSD: Makefile,v 1.16 2008/01/19 09:16:22 wiz Exp $
#

DISTNAME=		tanked-0.90
PKGREVISION=		2
CATEGORIES=		games x11
MASTER_SITES=		# empty

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://ogresoft.dyn.ml.org/tanked.html
COMMENT=		Multiplayer internet tank game for X11

USE_TOOLS=		imake
SETGIDGAME=		yes

post-patch:
	@${TOUCH} ${WRKSRC}/client/tanked.man
	@${MV} ${WRKSRC}/server/maps.list ${WRKSRC}/server/maps.list.bak
	@${SED} -e 's@XXX@${PREFIX}/share/tanked/@' \
		< ${WRKSRC}/server/maps.list.bak > ${WRKSRC}/server/maps.list

.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
