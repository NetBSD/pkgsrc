# $NetBSD: Makefile,v 1.3 2021/09/18 03:53:43 mef Exp $

R_PKGNAME=	nimble
R_PKGVER=	0.11.1

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	MCMC, Particle Filtering, and Programmable Hierarchical Modeling
LICENSE=	modified-bsd OR gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-R6-[0-9]*:../../devel/R-R6
DEPENDS+=	R-coda>=0.19.3:../../math/R-coda
DEPENDS+=	R-igraph>=1.2.4.1:../../math/R-igraph

TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat

USE_LANGUAGES=	c++ fortran

EIGEN_FILES+=	PardisoSupport
EIGEN_FILES+=	src/Core/Assign_MKL.h
EIGEN_FILES+=	src/Core/arch/AltiVec/PacketMath.h
EIGEN_FILES+=	src/Core/arch/SSE/PacketMath.h
EIGEN_FILES+=	src/Core/arch/ZVector/PacketMath.h
EIGEN_FILES+=	src/Core/util/BlasUtil.h
EIGEN_FILES+=	src/Core/util/DisableStupidWarnings.h
EIGEN_FILES+=	src/Core/util/MKL_support.h
EIGEN_FILES+=	src/Core/util/Meta.h
EIGEN_FILES+=	src/Geometry/Scaling.h
EIGEN_FILES+=	src/misc/lapacke.h

post-extract:
.for f in ${EIGEN_FILES}
	${CHMOD} a-x ${WRKSRC}/inst/include/Eigen/${f}
.endfor

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
