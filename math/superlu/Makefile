# $NetBSD: Makefile,v 1.29 2020/02/26 16:29:43 wiz Exp $

DISTNAME=		superlu-5.2.1
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_GITHUB:=xiaoyeli/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://portal.nersc.gov/project/sparse/superlu/
COMMENT=		Library for solving large, sparse, nonsymmetric systems of linear equations

DEPENDS+=		blas-[0-9]*:../../math/blas

USE_CMAKE=		yes
USE_LANGUAGES=		c fortran
TEST_TARGET=		test

.include "../../mk/bsd.pkg.mk"
