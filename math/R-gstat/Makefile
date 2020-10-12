# $NetBSD: Makefile,v 1.13 2020/10/12 21:52:01 bacon Exp $

R_PKGNAME=	gstat
R_PKGVER=	2.0-2
PKGREVISION=	1
CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Spatial and spatio-temporal geostatistical modelling, prediction and simulation
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-FNN>=1.1.3:../../math/R-FNN
DEPENDS+=	R-sp>=0.9.98:../../math/R-sp
DEPENDS+=	R-spacetime>=1.0.0:../../math/R-spacetime
DEPENDS+=	R-zoo>=1.8.3:../../math/R-zoo

USE_LANGUAGES+=	c fortran

.include "../../math/R/Makefile.extension"
.include "../../mk/blas.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
