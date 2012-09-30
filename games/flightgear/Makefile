# $NetBSD: Makefile,v 1.27 2012/09/30 10:04:33 dholland Exp $

DISTNAME=	flightgear-2.8.0
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.flightgear.org/pub/fgfs/Source/ \
		http://mirrors.ibiblio.org/pub/mirrors/flightgear/ftp/Source/ \
		ftp://ftp.kingmont.com/flightsims/flightgear/Source/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.flightgear.org/
COMMENT=	The FlightGear Simulator
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_CMAKE=		yes
CMAKE_ARGS+=		-DJPEG_FACTORY:BOOL=ON
CMAKE_ARGS+=		-DCMAKE_INSTALL_MANDIR=${PKGMANDIR}

.include "../../mk/jpeg.buildlink3.mk"
.include "../../audio/freealut/buildlink3.mk"
.include "../../audio/openal/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../games/plib/buildlink3.mk"
BUILDLINK_API_DEPENDS.simgear+=	simgear>=2.0.0
.include "../../games/simgear/buildlink3.mk"
.include "../../graphics/glut/buildlink3.mk"
.include "../../graphics/osg/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
