# $NetBSD: Makefile,v 1.2 2012/12/08 22:47:40 adam Exp $

DISTNAME=	Release-1.1.2
PKGNAME=	${DISTNAME:S/Release/openimageio/}
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/OpenImageIO/oiio/archive/
FETCH_USING=	curl

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://sites.google.com/site/openimageio/
COMMENT=	OpenImageIO is a library for reading and writing images
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/oiio-${DISTNAME}/src

USE_CMAKE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake

CXXFLAGS+=		-std=c++0x

CMAKE_ARGS+=		-DILMBASE_HOME:STRING=${BUILDLINK_PREFIX.ilmbase}
CMAKE_ARGS+=		-DOPENJPEG_HOME:STRING=${BUILDLINK_PREFIX.openjpeg15}
CMAKE_ARGS+=		-DOPENEXR_HOME:STRING=${BUILDLINK_PREFIX.openexr}

post-patch:
	${RM} -f ${WRKSRC}/include/tbb/tbb_machine.h.orig
	${RM} -f ${WRKSRC}/include/tbb/tbb_misc.h.orig

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/hdf5/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/ilmbase/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/opencv/buildlink3.mk"
.include "../../graphics/openjpeg15/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt4-tools=	build
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
