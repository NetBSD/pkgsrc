# $NetBSD: Makefile,v 1.8 2023/06/17 12:41:53 mef Exp $

R_PKGNAME=	nimble
R_PKGVER=	1.0.1

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	MCMC, Particle Filtering, and Programmable Hierarchical Modeling
LICENSE=	modified-bsd OR gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-R6-[0-9]*:../../devel/R-R6
DEPENDS+=	R-coda>=0.19.3:../../math/R-coda
DEPENDS+=	R-igraph>=1.2.4.1:../../math/R-igraph
DEPENDS+=	R-numDeriv-[0-9]*:../../math/R-numDeriv
DEPENDS+=	R-pracma-[0-9]*:../../math/R-pracma

TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat

USE_LANGUAGES=	c++ fortran
USE_TOOLS+=	gmake

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
