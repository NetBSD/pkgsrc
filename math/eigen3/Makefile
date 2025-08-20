# $NetBSD: Makefile,v 1.21 2025/08/20 11:35:05 wiz Exp $

DISTNAME=	eigen-3.4.0
PKGNAME=	${DISTNAME:S/eigen/eigen3/}
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITLAB:=libeigen/eigen/-/archive/${PKGVERSION_NOREV}/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://eigen.tuxfamily.org/
COMMENT=	C++ template library for linear algebra
LICENSE=	mpl-2.0

USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DCMAKEPACKAGE_INSTALL_DIR=${PREFIX}/lib/cmake/eigen3
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_EXPORT_NO_PACKAGE_REGISTRY=ON
CMAKE_CONFIGURE_ARGS+=	-DEIGEN_BUILD_PKGCONFIG=ON
CMAKE_CONFIGURE_ARGS+=	-DPKGCONFIG_INSTALL_DIR=${PREFIX}/lib/pkgconfig
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

# header-only
# PKGCONFIG_OVERRIDE+=	eigen3.pc.in

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
