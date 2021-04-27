# $NetBSD: Makefile,v 1.1 2021/04/27 15:16:46 thor Exp $

GITHUB_PROJECT=	flann
GITHUB_TAG=	1.9.1
DISTNAME=	1.9.1
PKGNAME=	${GITHUB_PROJECT}-lib-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=mariusmuja/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	thomas.orgis@uni-hamburg.de
HOMEPAGE=	https://github.com/mariusmuja/flann/
COMMENT=	Fast Library for Approximate Nearest Neighbors
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/flann-1.9.1
USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DBUILD_DOC=OFF
CMAKE_ARGS+=	-DBUILD_PYTHON_BINDINGS=OFF
CMAKE_ARGS+=	-DBUILD_MATLAB_BINDINGS=OFF
# Need to check if those two are out of experimental stage.
# MPI needs parallel HDF5.
CMAKE_ARGS+=	-DUSE_MPI=OFF
CMAKE_ARGS+=	-DBUILD_CUDA_LIB=OFF

PKGCONFIG_OVERRIDE+=	cmake/flann.pc.in

.include "../../devel/hdf5-c++/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
