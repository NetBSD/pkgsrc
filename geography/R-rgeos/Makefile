# $NetBSD: Makefile,v 1.3 2021/09/20 05:39:38 mef Exp $

R_PKGNAME=	rgeos
R_PKGVER=	0.5-7
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Interface to Geometry Engine - Open Source ('GEOS')
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

# Packages suggested but not available: 'maptools', 'XML', 'rgdal'
TEST_DEPENDS+=	R-maps-[0-9]*:../../geography/R-maps
TEST_DEPENDS+=	R-maptools-[0-9]*:../../geography/R-maptools
TEST_DEPENDS+=	R-rgdal-[0-9]*:../../geography/R-rgdal
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-XML-[0-9]*:../../math/R-XML

USE_LANGUAGES+=	c c++

.include "../../math/R/Makefile.extension"
.include "../../geography/geos/buildlink3.mk"
.include "../../math/R-sp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
