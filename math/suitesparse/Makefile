# $NetBSD: Makefile,v 1.16 2026/02/14 15:11:59 ktnb Exp $

DISTNAME=	SuiteSparse-7.12.2
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=DrTimothyAldenDavis/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://people.engr.tamu.edu/davis/suitesparse.html
COMMENT=	Set of packages for sparse matrices calculation
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS=	pkg-config

WRKSRC=		${WRKDIR}/${DISTNAME}

CMAKE_CONFIGURE_ARGS+=	-DBLA_VENDOR=Generic
CMAKE_CONFIGURE_ARGS+=	-DBLA_PREFER_PKGCONFIG=true
CMAKE_CONFIGURE_ARGS+=	-DBLA_PKGCONFIG_BLAS=${BLAS_PC}

.include "../../devel/cmake/build.mk"
.include "../../mk/blas.buildlink3.mk"
.include "../../math/metis/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/openmp.mk"
.include "../../mk/bsd.pkg.mk"
