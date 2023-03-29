# $NetBSD: Makefile,v 1.16 2023/03/29 08:50:27 wiz Exp $

DISTNAME=	eigen-3.4.0
PKGNAME=	${DISTNAME:S/eigen/eigen3/}
CATEGORIES=	math
MASTER_SITES=	https://gitlab.com/libeigen/eigen/-/archive/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://eigen.tuxfamily.org/
COMMENT=	C++ template library for linear algebra
LICENSE=	mpl-2.0

WRKSRC=		${WRKDIR}/eigen-3147391d946bb4b6c68edd901f2add6ac1f31f8c

USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DCMAKEPACKAGE_INSTALL_DIR=${PREFIX}/lib/cmake/eigen3
CMAKE_ARGS+=	-DCMAKE_EXPORT_NO_PACKAGE_REGISTRY=ON
CMAKE_ARGS+=	-DEIGEN_BUILD_PKGCONFIG=ON
CMAKE_ARGS+=	-DPKGCONFIG_INSTALL_DIR=${PREFIX}/lib/pkgconfig

# header-only
# PKGCONFIG_OVERRIDE+=	eigen3.pc.in

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
