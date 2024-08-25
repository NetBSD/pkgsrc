# $NetBSD: Makefile,v 1.2 2024/08/25 06:19:01 wiz Exp $

DISTNAME=	scalapack-2.2.0
CATEGORIES=	math
MASTER_SITES=	http://www.netlib.org/scalapack/
EXTRACT_SUFX=	.tgz

MAINTAINER=	thor@NetBSD.org
HOMEPAGE=	http://www.netlib.org/scalapack/
COMMENT=	Scalable Linear Algebra PACKage
LICENSE=	modified-bsd

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c fortran

CMAKE_CONFIGURE_ARGS=	-DBLA_PREFER_PKGCONFIG=on \
		-DBLA_PKGCONFIG_LAPACK=${LAPACK_PC:Q} \
		-DBLA_PKGCONFIG_BLAS=${BLAS_PC:Q} \
		-DBUILD_SHARED_LIBS=ON

TEST_TARGET=	test
TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/lib

PKGCONFIG_OVERRIDE+=	scalapack.pc.in

.include "../../mk/blas.buildlink3.mk"
.include "../../mk/mpi.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
