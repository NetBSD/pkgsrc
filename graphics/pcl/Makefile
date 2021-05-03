# $NetBSD: Makefile,v 1.1 2021/05/03 06:25:11 thor Exp $

GITHUB_PROJECT=	pcl
GITHUB_TAG=	pcl-${PKGVERSION}
DISTNAME=	pcl-1.11.1
PLIST_SUBST+=	PCL_V=1.11
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=PointCloudLibrary/}

MAINTAINER=	thomas.orgis@uni-hamburg.de
HOMEPAGE=	https://github.com/PointCloudLibrary/pcl/
COMMENT=	2D/3D image and point cloud processing
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/pcl-pcl-${PKGVERSION}
USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

CMAKE_ARGS+=	-DWITH_QHULL=TRUE
# Those could be enabled as options if desired.
CMAKE_ARGS+=	-DWITH_CUDA=FALSE
CMAKE_ARGS+=	-DWITH_QT=FALSE

.include "../../graphics/pcl/depends.mk"

.include "../../mk/bsd.pkg.mk"
