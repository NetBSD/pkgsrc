# $NetBSD: Makefile,v 1.7 2013/01/24 01:51:13 wen Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/gstat/
COMMENT=	Uni/multivariable geostatistical modelling, prediction and simulation
LICENSE=	gnu-gpl-v2

R_PKGNAME=	gstat
R_PKGVER=	1.0-15

DEPENDS+=	R-sp>=0.9.98:../../math/R-sp
DEPENDS+=	R-spacetime>=1.0.0:../../math/R-spacetime

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
