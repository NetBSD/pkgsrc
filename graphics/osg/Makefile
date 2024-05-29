# $NetBSD: Makefile,v 1.179 2024/05/29 16:33:00 adam Exp $

DISTNAME=	osg-3.6.5
PKGREVISION=	54
CATEGORIES=	graphics devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=openscenegraph/}
GITHUB_PROJECT=	OpenSceneGraph
GITHUB_TAG=	OpenSceneGraph-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.openscenegraph.org/
COMMENT=	High performance 3D graphics toolkit
LICENSE=	gnu-lgpl-v2.1

WRKSRC=			${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config
PKGCONFIG_OVERRIDE=	packaging/pkgconfig/openscenegraph.pc.in
PKGCONFIG_OVERRIDE+=	packaging/pkgconfig/openthreads.pc.in

CMAKE_ARGS+=		-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=		-DDYNAMIC_OPENSCENEGRAPH=ON
CMAKE_ARGS+=		-DBUILD_OSG_EXAMPLES=OFF
CMAKE_ARGS+=		-DCMAKE_DISABLE_FIND_PACKAGE_Asio=TRUE
CMAKE_ARGS+=		-DCMAKE_DISABLE_FIND_PACKAGE_SDL=TRUE # disable legacy SDL
CMAKE_ARGS+=		-DCMAKE_DISABLE_FIND_PACKAGE_GTA=TRUE
CMAKE_ARGS+=		-DCMAKE_DISABLE_FIND_PACKAGE_Inventor=TRUE
CMAKE_ARGS+=		-DCMAKE_DISABLE_FIND_PACKAGE_LIBLAS=TRUE
CMAKE_ARGS+=		-DCMAKE_DISABLE_FIND_PACKAGE_LibVNCServer=TRUE
CMAKE_ARGS+=		-DCMAKE_DISABLE_FIND_PACKAGE_GLIB=TRUE
CMAKE_ARGS+=		-DCMAKE_DISABLE_FIND_PACKAGE_GStreamer=TRUE
CMAKE_ARGS+=		-DCMAKE_DISABLE_FIND_PACKAGE_GtkGl=TRUE
CMAKE_ARGS+=		-DCMAKE_DISABLE_FIND_PACKAGE_OpenCascade=TRUE
CMAKE_ARGS+=		-DCMAKE_DISABLE_FIND_PACKAGE_DCMTK=TRUE
CMAKE_ARGS+=		-DCMAKE_DISABLE_FIND_PACKAGE_NVTT=TRUE
CMAKE_ARGS+=		-DCMAKE_DISABLE_FIND_PACKAGE_ZeroConf=TRUE
CMAKE_ARGS+=		-DCMAKE_DISABLE_FIND_PACKAGE_DirectInput=TRUE
CMAKE_ARGS+=		-DCMAKE_DISABLE_FIND_PACKAGE_DirectShow=TRUE
CMAKE_ARGS+=		-DCMAKE_DISABLE_FIND_PACKAGE_COLLADA=TRUE
CMAKE_ARGS+=		-DCMAKE_DISABLE_FIND_PACKAGE_FBX=TRUE
CMAKE_ARGS+=		-DOSG_USE_LOCAL_LUA_SOURCE=OFF

PLIST_VARS+=	quartz notdarwin

.include "../../mk/bsd.prefs.mk"

# jasper uses SIZE_MAX and friends in its headers.
CXXFLAGS+=	-D__STDC_LIMIT_MACROS

.include "options.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jasper/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../lang/lua52/buildlink3.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.if ${OPSYS} != "Darwin"
PLIST.notdarwin=	yes
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.else
PLIST.quartz=		yes
.endif
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
