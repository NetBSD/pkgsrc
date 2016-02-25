# $NetBSD: Makefile,v 1.8 2016/02/25 01:59:08 wen Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/gstat/
COMMENT=	Uni/multivariable geostatistical modelling, prediction and simulation
LICENSE=	gnu-gpl-v2

R_PKGNAME=	gstat
R_PKGVER=	1.1-2

DEPENDS+=	R-sp>=0.9.98:../../math/R-sp
DEPENDS+=	R-spacetime>=1.0.0:../../math/R-spacetime
DEPENDS+=	R-FNN>=0:../../math/R-FNN

.include "../../math/R/Makefile.extension"
.include "../../math/blas/buildlink3.mk"
.include "../../lang/g95/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
