# $NetBSD: Makefile,v 1.85 2018/09/02 21:32:41 wiz Exp $

DISTNAME=	osg-3.4.1
PKGREVISION=	3
CATEGORIES=	graphics devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=openscenegraph/}
GITHUB_PROJECT=	OpenSceneGraph
GITHUB_TAG=	OpenSceneGraph-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.openscenegraph.org/
COMMENT=	High performance 3D graphics toolkit
LICENSE=	gnu-lgpl-v2.1

EXTRACT_USING=		bsdtar

WRKSRC=			${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

USE_CMAKE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config
PKGCONFIG_OVERRIDE=	packaging/pkgconfig/openscenegraph.pc.in
PKGCONFIG_OVERRIDE+=	packaging/pkgconfig/openthreads.pc.in

CMAKE_ARGS+=		-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=		-DDYNAMIC_OPENSCENEGRAPH=ON
CMAKE_ARGS+=		-DOSG_USE_LOCAL_LUA_SOURCE=OFF
CMAKE_ARGS+=		-DOSG_USE_QT=OFF
CMAKE_ARGS+=		-DBUILD_OSG_EXAMPLES=OFF
CMAKE_ARGS+=		-DCMAKE_DISABLE_FIND_PACKAGE_SDL=TRUE # disable legacy SDL
CMAKE_ARGS+=		-DCMAKE_DISABLE_FIND_PACKAGE_Lua51=TRUE # use Lua52
CMAKE_ARGS+=		-DCMAKE_DISABLE_FIND_PACKAGE_GTA=TRUE
CMAKE_ARGS+=		-DCMAKE_DISABLE_FIND_PACKAGE_Inventor=TRUE
CMAKE_ARGS+=		-DCMAKE_DISABLE_FIND_PACKAGE_LIBLAS=TRUE
CMAKE_ARGS+=		-DCMAKE_DISABLE_FIND_PACKAGE_LibVNCServer=TRUE
CMAKE_ARGS+=		-DCMAKE_DISABLE_FIND_PACKAGE_Xine=TRUE
CMAKE_ARGS+=		-DCMAKE_DISABLE_FIND_PACKAGE_GLIB=TRUE
CMAKE_ARGS+=		-DCMAKE_DISABLE_FIND_PACKAGE_GStreamer=TRUE
CMAKE_ARGS+=		-DCMAKE_DISABLE_FIND_PACKAGE_GtkGl=TRUE

PLIST_VARS+=	quartz x11

.include "../../mk/bsd.prefs.mk"

# jasper uses SIZE_MAX and friends in its headers.
CXXFLAGS+=	-D__STDC_LIMIT_MACROS

.include "options.mk"

.if ${OPSYS} != "Darwin"
PLIST.x11=	yes
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.else
PLIST.quartz=	yes
.endif
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
