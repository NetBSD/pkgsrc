# $NetBSD: Makefile,v 1.5 2021/09/20 05:19:08 mef Exp $

R_PKGNAME=	maptools
R_PKGVER=	1.1-2
CATEGORIES=	geography

MAINTAINER=	wen@NetBSD.org
COMMENT=	Tools for handling spatial objects
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-sp>=1.0.11:../../math/R-sp

# Packages suggested but not available:
#   'spatstat.geom', 'PBSmapping', 'maps', 'RColorBrewer', 'raster',
#   'polyclip', 'plotrix', 'spatstat.linnet', 'spatstat.utils',
#   'spatstat'
TEST_DEPENDS+=	R-rgeos-[0-9]*:../../geography/R-rgeos

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
