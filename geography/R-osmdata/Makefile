# $NetBSD: Makefile,v 1.3 2024/11/29 15:31:15 mef Exp $

R_PKGNAME=	osmdata
R_PKGVER=	0.2.5
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Import 'OpenStreetMap' Data as Simple Features or Spatial Objects
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-Rcpp-[0-9]*:../../devel/R-Rcpp
DEPENDS+=	R-crsmeta-[0-9]*:../../geography/R-crsmeta
DEPENDS+=	R-curl>=4.2:../../www/R-curl
DEPENDS+=	R-httr>=1.4.1:../../www/R-httr
DEPENDS+=	R-httr2-[0-9]*:../../www/R-httr2
DEPENDS+=	R-jsonlite>=1.6:../../textproc/R-jsonlite
DEPENDS+=	R-lubridate>=1.7.4:../../time/R-lubridate
DEPENDS+=	R-magrittr>=1.5:../../devel/R-magrittr
DEPENDS+=	R-proj4-[0-9]*:../../geography/R-proj4
DEPENDS+=	R-reproj-[0-9]*:../../geography/R-reproj
DEPENDS+=	R-rvest>=0.3.5:../../www/R-rvest
DEPENDS+=	R-sp>=1.3.1:../../math/R-sp
DEPENDS+=	R-tibble>=2.1.3:../../math/R-tibble
DEPENDS+=	R-xml2>=1.2.2nb1:../../textproc/R-xml2

# Package suggested but not available: 'httptest2'

TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-markdown-[0-9]*:../../textproc/R-markdown
TEST_DEPENDS+=	R-raster-[0-9]*:../../geography/R-raster
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-sf-[0-9]*:../../geography/R-sf
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat

USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
