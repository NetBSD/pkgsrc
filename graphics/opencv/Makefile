# $NetBSD: Makefile,v 1.52 2015/01/06 14:28:12 jperkin Exp $

DISTNAME=	opencv-2.4.9
PKGREVISION=	2
CATEGORIES=	graphics devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=opencvlibrary/}
EXTRACT_SUFX=	.zip

MAINTAINER=	anthony.mallet@laas.fr
HOMEPAGE=	http://code.opencv.org/projects/OpenCV/wiki/WikiStart
COMMENT=	Library for computer vision problems
LICENSE=	modified-bsd

USE_CMAKE=		yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config

INSTALLATION_DIRS+=	share/doc/opencv/papers
INSTALLATION_DIRS+=	share/doc/opencv/ref/pics
INSTALLATION_DIRS+=	share/OpenCV/haarcascades

PKGCONFIG_OVERRIDE+=	opencv.pc.cmake.in

REPLACE_PYTHON+=	samples/python/*.py

WRKSRC=		${WRKDIR}/${DISTNAME:S/a$//}

# includes configure output and paths to gmake etc.
CHECK_WRKREF_SKIP=	${PREFIX}/lib/libopencv_core.*

.include "options.mk"

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
CXXFLAGS+=	-std=c++11
.endif

OPSYSVARS+=		CMAKE_ARGS
CMAKE_ARGS+=		-DZLIB_ROOT=${BUILDLINK_PREFIX.zlib}
CMAKE_ARGS.SunOS+=	-DENABLE_PRECOMPILED_HEADERS=NO

PLIST_VARS+=	opencl

.if ${OPSYS} == "Darwin" || ${OPSYS} == "NetBSD" || ${OPSYS} == "SunOS" || ${OPSYS} == "Linux"
PLIST.opencl=	yes
.endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jasper/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
