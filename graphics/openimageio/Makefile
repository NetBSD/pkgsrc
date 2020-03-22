# $NetBSD: Makefile,v 1.64 2020/03/22 21:24:23 joerg Exp $

OIIOVER=	1.8.15
DISTNAME=	oiio-Release-${OIIOVER}
PKGNAME=	${DISTNAME:S/oiio-Release/openimageio/}
PKGREVISION=	13
CATEGORIES=	graphics
MASTER_SITES=	-https://github.com/OpenImageIO/oiio/archive/Release-${OIIOVER}.tar.gz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://sites.google.com/site/openimageio/
COMMENT=	OpenImageIO is a library for reading and writing images
LICENSE=	modified-bsd

UNLIMIT_RESOURCES=	datasize virtualsize

USE_CMAKE=		yes
USE_LANGUAGES=		c gnu++11
BUILDLINK_TRANSFORM+=	rm:-std=c++11 # for alloca(3)
USE_TOOLS+=		gmake

OBJDIR=			../build
CONFIGURE_DIRS=		${OBJDIR}
CMAKE_ARG_PATH=		${WRKSRC}

CXXFLAGS.Linux+=	-pthread

CMAKE_ARGS+=		-DILMBASE_HOME:STRING=${BUILDLINK_PREFIX.ilmbase}
CMAKE_ARGS+=		-DOPENJPEG_HOME:STRING=${BUILDLINK_PREFIX.openjpeg}
CMAKE_ARGS+=		-DOPENEXR_HOME:STRING=${BUILDLINK_PREFIX.openexr}
CMAKE_ARGS+=		-DINSTALL_DOCS:BOOL=OFF
CMAKE_ARGS+=		-DUSE_LIBRAW:BOOL=OFF
CMAKE_ARGS+=		-DUSE_OCIO:BOOL=OFF
CMAKE_ARGS+=		-DUSE_PYTHON:BOOL=OFF

# For redefinition of _rotl macro.
BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/hdf5/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/ilmbase/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/opencv/buildlink3.mk"
.include "../../graphics/openjpeg/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
CXXFLAGS+=	-Wno-deprecated-register
.endif

pre-configure:
	${MKDIR} ${WRKDIR}/build

.include "../../mk/bsd.pkg.mk"
