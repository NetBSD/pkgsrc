# $NetBSD: Makefile,v 1.32 2026/09/02 19:02:26 wiz Exp $

R_PKGNAME=	terra
R_PKGVER=	1.9-34
PKGREVISION=	2
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

USE_LANGUAGES=		c c++
USE_CXX_FEATURES=	c++17

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../geography/gdal-lib/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
.include "../../print/poppler/buildlink3.mk"
.include "../../geography/libspatialite/buildlink3.mk"
.include "../../textproc/json-c/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
