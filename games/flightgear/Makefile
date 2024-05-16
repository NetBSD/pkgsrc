# $NetBSD: Makefile,v 1.171 2024/05/16 06:14:54 wiz Exp $

DISTNAME=	flightgear-2020.3.11
PKGREVISION=	41
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=flightgear/release-${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.flightgear.org/
COMMENT=	The FlightGear Simulator
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

USE_LANGUAGES=		c c++
USE_CMAKE=		yes
LDFLAGS.NetBSD+=	-lexecinfo

CONFIGURE_DIRS=		fgbuild
BUILD_DIRS=		fgbuild
CMAKE_ARG_PATH=		..

CMAKE_ARGS+=		-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=		-DFG_BUILD_TYPE=Release

CMAKE_ARGS+=		-DSYSTEM_FLITE=OFF
CMAKE_ARGS+=		-DSYSTEM_HTS_ENGINE=OFF

# The cmake script warns against building in the source directory.
pre-configure:
	cd ${WRKSRC} && ${MKDIR} fgbuild

.include "../../audio/gsm/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../audio/speexdsp/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
BUILDLINK_API_DEPENDS.libevent+=	libevent>=2
.include "../../devel/libevent/buildlink3.mk"
.include "../../games/plib/buildlink3.mk"
BUILDLINK_API_DEPENDS.simgear+=	simgear>=2019.1.1
.include "../../games/simgear/buildlink3.mk"
.include "../../graphics/freeglut/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/osg/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtquickcontrols2/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
