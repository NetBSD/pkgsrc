# $NetBSD: Makefile,v 1.31 2020/10/13 12:11:07 bacon Exp $

DISTNAME=		superlu-5.2.1
PKGREVISION=		2
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_GITHUB:=xiaoyeli/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://portal.nersc.gov/project/sparse/superlu/
COMMENT=		Library for solving large, sparse, nonsymmetric systems of linear equations

USE_CMAKE=		yes
USE_LANGUAGES=		c fortran
TEST_TARGET=		test


.include "../../mk/blas.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
