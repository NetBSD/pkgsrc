# $NetBSD: Makefile,v 1.1.1.1 2012/04/01 17:46:27 brook Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/RandomFields/
COMMENT=	Simulation and analysis of random fields
# LICENSE=	GPL (gnu-gpl-v?)

R_PKGNAME=	RandomFields
R_PKGVER=	2.0.54

USE_LANGUAGES+=	c c++ fortran

.include "../../math/R/Makefile.extension"
.include "../../math/blas/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
