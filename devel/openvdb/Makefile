# $NetBSD: Makefile,v 1.1 2026/11/08 15:45:05 ryoon Exp $

DISTNAME=	openvdb-13.0.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=AcademySoftwareFoundation/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/AcademySoftwareFoundation/openvdb/
COMMENT=	Sparse volume data structure and tools
LICENSE=	apache-2.0

USE_LANGUAGES=	c++
USE_TOOLS+=	pkg-config

.include "../../devel/cmake/build.mk"
.include "../../devel/blosc/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../parallel/threadingbuildingblocks/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
