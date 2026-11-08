# $NetBSD: Makefile,v 1.1 2026/11/08 16:12:54 ryoon Exp $

DISTNAME=	ceres-solver-2.2.0
CATEGORIES=	math
MASTER_SITES=	http://ceres-solver.org/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://ceres-solver.org/
COMMENT=	C++ library for modeling and solving optimization problems
LICENSE=	modified-bsd

USE_LANGUAGES=		c c++
USE_CXX_FEATURES+=	c++17

#CMAKE_CONFIGURE_ARGS+=	-DSUITESPARSE=OFF
CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED_LIBS=ON

.include "../../devel/cmake/build.mk"
.include "../../devel/gflags/buildlink3.mk"
.include "../../devel/google-glog/buildlink3.mk"
.include "../../math/eigen3/buildlink3.mk"
.include "../../math/metis/buildlink3.mk"
.include "../../math/suitesparse/buildlink3.mk"
.include "../../mk/blas.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
