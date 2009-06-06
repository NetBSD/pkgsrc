# $NetBSD: Makefile,v 1.2 2009/06/06 22:04:50 wiz Exp $
#

DISTNAME=	ioquake3-1.36
CATEGORIES=	games
MASTER_SITES=	http://ioquake3.org/files/1.36/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ioquake3.org/
COMMENT=	Open source Quake 3 distribution

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake
BUILD_TARGET=	release

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/ioquake3
	cd ${WRKSRC} && ${GMAKE} copyfiles COPYDIR=${DESTDIR}${PREFIX}/lib/ioquake3

.include "../../audio/openal/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
