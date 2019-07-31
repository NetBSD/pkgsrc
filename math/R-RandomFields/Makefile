# $NetBSD: Makefile,v 1.4 2019/07/31 18:34:10 brook Exp $

CATEGORIES=	math R

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/RandomFields/
COMMENT=	Simulation and analysis of random fields
LICENSE=	gnu-gpl-v3

R_PKGNAME=	RandomFields
R_PKGVER=	3.3.6

DEPENDS+=	R-sp>=1.3.1:../../math/R-sp

USE_LANGUAGES+=	c c++ fortran

.include "../../math/R/Makefile.extension"
.include "../../math/R-RandomFieldsUtils/buildlink3.mk"
.include "../../math/blas/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
