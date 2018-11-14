# $NetBSD: Makefile,v 1.18 2018/11/14 22:21:43 kleink Exp $

DISTNAME=	opencv-2.4.11
PKGREVISION=	12
CATEGORIES=	graphics devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=opencvlibrary/}
EXTRACT_SUFX=	.zip

MAINTAINER=	anthony.mallet@laas.fr
HOMEPAGE=	https://opencv.org/
COMMENT=	Library for computer vision problems
LICENSE=	modified-bsd

USE_CMAKE=		yes
USE_LANGUAGES=		c c++11
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config

INSTALLATION_DIRS+=	share/doc/opencv/papers
INSTALLATION_DIRS+=	share/doc/opencv/ref/pics
INSTALLATION_DIRS+=	share/OpenCV/haarcascades

PKGCONFIG_OVERRIDE+=	opencv.pc.cmake.in

REPLACE_PYTHON+=	samples/python/*.py

WRKSRC=		${WRKDIR}/${DISTNAME:S/a$//}

# jasper uses SIZE_MAX and friends in its headers.
CXXFLAGS+=	-D__STDC_LIMIT_MACROS

# includes configure output and paths to gmake etc.
CHECK_WRKREF_SKIP=	${PREFIX}/lib/libopencv_core.*

.include "options.mk"

CMAKE_ARGS+=		-DZLIB_ROOT=${BUILDLINK_PREFIX.zlib}
CMAKE_ARGS+=		-DENABLE_PRECOMPILED_HEADERS=NO

PLIST_VARS+=	opencl

.if ${OPSYS} == "Darwin" || ${OPSYS} == "NetBSD" || ${OPSYS} == "SunOS" || ${OPSYS} == "Linux" || ${OPSYS} == "FreeBSD"
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
