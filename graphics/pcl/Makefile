# $NetBSD: Makefile,v 1.55 2025/09/27 09:57:21 wiz Exp $

DISTNAME=	pcl-1.15.1
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=PointCloudLibrary/}
GITHUB_TAG=	pcl-${PKGVERSION_NOREV}

MAINTAINER=	thomas.orgis@uni-hamburg.de
HOMEPAGE=	https://github.com/PointCloudLibrary/pcl
COMMENT=	2D/3D image and point cloud processing
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/pcl-${DISTNAME}

USE_CXX_FEATURES+=	c++17 filesystem
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config

# Those could be enabled as options if desired.
CMAKE_CONFIGURE_ARGS+=		-DWITH_CUDA=FALSE
# test is missing
CMAKE_CONFIGURE_ARGS.NetBSD+=	-DHAVE_POSIX_MEMALIGN=1

.include "../../mk/compiler.mk"

.include "../../mk/openmp.mk"

# See LIBATOMIC_NOT_NEEDED in CMakeLists.txt
.if ${PKGSRC_COMPILER:Mgcc}
.include "../../devel/libatomic/buildlink3.mk"
.endif

.include "options.mk"

PCL_BASE_VERSION=	${PKGVERSION_NOREV:C/([0-9]+\.[0-9]+).*/\1/}
PLIST_SUBST+=		PCL_BASE_VERSION=${PCL_BASE_VERSION}
# \todo PLIST_AWK to emit ${PCL_BASE_VERSION}

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../math/eigen3/buildlink3.mk"
.include "../../math/flann-lib/buildlink3.mk"
.include "../../math/qhull/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../textproc/PEGTL/buildlink3.mk"
.include "../../textproc/cJSON/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/utf8-cpp/buildlink3.mk"
# Not used correctly right now, see
# https://github.com/PointCloudLibrary/pcl/issues/4744
#.include "../../devel/metslib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
