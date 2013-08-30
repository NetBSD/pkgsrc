# $NetBSD: Makefile,v 1.2 2013/08/30 13:05:00 joerg Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/RandomFields/
COMMENT=	Simulation and analysis of random fields
LICENSE=	gnu-gpl-v2

R_PKGNAME=	RandomFields
R_PKGVER=	2.0.66

USE_LANGUAGES+=	c c++ fortran

.include "../../math/R/Makefile.extension"
.include "../../math/blas/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
