# $NetBSD: Makefile,v 1.2 2020/11/05 09:08:16 ryoon Exp $

R_PKGNAME=	sf
R_PKGVER=	0.9-5
PKGREVISION=	1
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Simple Features for R
LICENSE=	mit OR gnu-gpl-v2

USE_LANGUAGES+=	c c++11

DEPENDS+=	R-magrittr>=1.5:../../devel/R-magrittr
DEPENDS+=	R-rgeos>=0.5.2:../../geography/R-rgeos
DEPENDS+=	R-DBI>=0.8:../../math/R-DBI
DEPENDS+=	R-classInt>=0.4.1:../../math/R-classInt
DEPENDS+=	R-units>=0.6.0:../../math/R-units

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../geography/gdal-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
