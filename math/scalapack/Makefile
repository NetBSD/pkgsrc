# $NetBSD: Makefile,v 1.5 2026/02/07 08:27:14 wiz Exp $

DISTNAME=	scalapack-2.2.0
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	https://www.netlib.org/scalapack/
EXTRACT_SUFX=	.tgz

MAINTAINER=	thor@NetBSD.org
HOMEPAGE=	https://www.netlib.org/scalapack/
COMMENT=	Scalable Linear Algebra PACKage
LICENSE=	modified-bsd

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c fortran

CFLAGS+=	-Wno-implicit-function-declaration

.include "../../devel/cmake/build.mk"
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
