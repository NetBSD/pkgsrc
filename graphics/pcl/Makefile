# $NetBSD: Makefile,v 1.19 2023/01/29 21:14:43 ryoon Exp $

DISTNAME=	pcl-1.11.1
PKGREVISION=	15
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=PointCloudLibrary/}
GITHUB_PROJECT=	pcl
GITHUB_TAG=	pcl-${PKGVERSION_NOREV}

MAINTAINER=	thomas.orgis@uni-hamburg.de
HOMEPAGE=	https://github.com/PointCloudLibrary/pcl/
COMMENT=	2D/3D image and point cloud processing
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/pcl-pcl-${PKGVERSION_NOREV}
USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

CMAKE_ARGS+=		-DWITH_QHULL=TRUE
# Those could be enabled as options if desired.
CMAKE_ARGS+=		-DWITH_CUDA=FALSE
CMAKE_ARGS+=		-DWITH_QT=FALSE
# test is missing
CMAKE_ARGS.NetBSD+=	-DHAVE_POSIX_MEMALIGN=1

.include "options.mk"

# Non-VTK install would still find GLEW and install a misleading
# CMake file for it. Avoid that by deletion after configure.
.if empty(PKG_OPTIONS:Mvtk)
pre-build:
	rm -f ${WRKSRC:Q}/cmake/Modules/FindGLEW.cmake
.endif

PLIST_SUBST+=	PCL_BASE_VERSION=${PKGVERSION_NOREV:C/([0-9]+\.[0-9]+).*/\1/}

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../math/flann-lib/buildlink3.mk"
.include "../../math/eigen3/buildlink3.mk"
.include "../../math/qhull/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/PEGTL/buildlink3.mk"
.include "../../textproc/utf8-cpp/buildlink3.mk"
# Not used correctly right now, see
# https://github.com/PointCloudLibrary/pcl/issues/4744
#.include "../../devel/metslib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
