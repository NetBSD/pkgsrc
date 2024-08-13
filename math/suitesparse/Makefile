# $NetBSD: Makefile,v 1.3 2024/08/13 13:19:13 ktnb Exp $

DISTNAME=	SuiteSparse-7.8.1
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=DrTimothyAldenDavis/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cise.ufl.edu/research/sparse/SuiteSparse/
COMMENT=	Set of packages for sparse matrices calculation
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2

USE_LANGUAGES=	c c++ fortran8

WRKSRC=		${WRKDIR}/${DISTNAME}

.include "../../devel/cmake/build.mk"
.include "../../mk/blas.buildlink3.mk"
.include "../../math/metis/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../math/openblas/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../parallel/openmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
