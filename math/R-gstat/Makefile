# $NetBSD: Makefile,v 1.6 2012/04/15 17:37:43 brook Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/gstat/
COMMENT=	Uni/multivariable geostatistical modelling, prediction and simulation
LICENSE=	gnu-gpl-v2

R_PKGNAME=	gstat
R_PKGVER=	1.0-10

DEPENDS+=	R-sp>=0.9.98:../../math/R-sp
DEPENDS+=	R-spacetime>=0.6.2:../../math/R-spacetime

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
