# $NetBSD: Makefile,v 1.2 2024/08/25 06:18:59 wiz Exp $

DISTNAME=	armadillo-12.6.7
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=arma/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/arma/
COMMENT=	C++ linear algebra library
LICENSE=	apache-2.0

USE_TOOLS+=		cmake pkg-config
USE_LANGUAGES+=		c c++
USE_CXX_FEATURES=	c++11
USE_CMAKE=		yes

CMAKE_CONFIGURE_ARGS+=	-DINSTALL_LIB_DIR=${PREFIX}/lib
CMAKE_CONFIGURE_ARGS+=	-DBLA_PREFER_PKGCONFIG=ON
CMAKE_CONFIGURE_ARGS+=	-DBLA_PKGCONFIG_BLAS=${BLAS_PC}
CMAKE_CONFIGURE_ARGS+=	-DBLA_PKGCONFIG_LAPACK=${LAPACK_PC}

.include "../../mk/blas.buildlink3.mk"
.include "../../math/superlu/buildlink3.mk"
.include "../../math/arpack-ng/buildlink3.mk"
# Armadillo references HDF5, but this is header-only and clients
# are supposed to link HDF5 themselves.
.include "../../mk/bsd.pkg.mk"
