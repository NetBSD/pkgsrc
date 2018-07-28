# $NetBSD: Makefile,v 1.10 2018/07/28 14:40:48 brook Exp $

CATEGORIES=	math

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
.include "../../mk/bsd.pkg.mk"
