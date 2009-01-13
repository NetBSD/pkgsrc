# $NetBSD: Makefile,v 1.1.1.1 2009/01/13 00:12:29 jmcneill Exp $
#

DISTNAME=	ioquake3-0.0.1490
CATEGORIES=	games
MASTER_SITES=	http://www.invisible.ca/~jmcneill/distfiles/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ioquake3.org/
COMMENT=	Open source Quake 3 distribution
USE_TOOLS+=	gmake

BUILD_TARGET=	release

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/ioquake3
	cd ${WRKSRC} && ${GMAKE} copyfiles COPYDIR=${DESTDIR}${PREFIX}/lib/ioquake3

.include "../../audio/openal/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
