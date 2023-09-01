# $NetBSD: Makefile,v 1.6 2023/09/01 11:34:59 nia Exp $

DISTNAME=	flann-1.9.2
PKGNAME=	${DISTNAME:S/-/-lib-/}
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=mariusmuja/}
GITHUB_PROJECT=	flann

MAINTAINER=	thomas.orgis@uni-hamburg.de
HOMEPAGE=	https://github.com/mariusmuja/flann
COMMENT=	Fast Library for Approximate Nearest Neighbors
LICENSE=	modified-bsd

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

CMAKE_ARGS+=	-DBUILD_DOC=OFF
CMAKE_ARGS+=	-DBUILD_PYTHON_BINDINGS=OFF
CMAKE_ARGS+=	-DBUILD_MATLAB_BINDINGS=OFF
# Need to check if those two are out of experimental stage.
# MPI needs parallel HDF5.
CMAKE_ARGS+=	-DUSE_MPI=OFF
CMAKE_ARGS+=	-DBUILD_CUDA_LIB=OFF

FORCE_CXX_STD=		c++11
USE_CXX_FEATURES+=	c++11

PKGCONFIG_OVERRIDE+=	cmake/flann.pc.in

.include "../../archivers/lz4/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/hdf5-c++/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
