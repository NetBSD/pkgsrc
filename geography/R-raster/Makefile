# $NetBSD: Makefile,v 1.3 2024/11/29 23:13:28 mef Exp $

R_PKGNAME=	raster
R_PKGVER=	3.6-30
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Geographic Data Analysis and Modeling
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-sp>=1.2.0:../../math/R-sp
DEPENDS+=	R-terra-[0-9]*:../../geography/R-terra

# Packages suggested but not available:
#   'rasterVis', 'fields', 'exactextractr'

TEST_DEPENDS+=	R-ncdf4-[0-9]*:../../math/R-ncdf4
TEST_DEPENDS+=	R-gstat-[0-9]*:../../math/R-gstat
TEST_DEPENDS+=	R-igraph-[0-9]*:../../math/R-igraph
TEST_DEPENDS+=	R-sf-[0-9]*:../../geography/R-sf
TEST_DEPENDS+=	R-tinytest-[0-9]*:../../devel/R-tinytest

USE_LANGUAGES+=	c c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../math/R-sp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
