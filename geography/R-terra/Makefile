# $NetBSD: Makefile,v 1.16 2025/02/08 09:57:55 mef Exp $

R_PKGNAME=	terra
R_PKGVER=	1.8-15
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Spatial Data Analysis
LICENSE=	gnu-gpl-v3

# Package suggested but not available: 'leaflet'
TEST_DEPENDS+=	R-tinytest-[0-9]*:../../devel/R-tinytest
TEST_DEPENDS+=	R-ncdf4-[0-9]*:../../math/R-ncdf4
TEST_DEPENDS+=	R-sf-[0-9]*:../../geography/R-sf
TEST_DEPENDS+=	R-deldir-[0-9]*:../../geography/R-deldir
TEST_DEPENDS+=	R-XML-[0-9]*:../../math/R-XML
TEST_DEPENDS+=	R-htmlwidgets-[0-9]*:../../www/R-htmlwidgets

USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../geography/gdal-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
