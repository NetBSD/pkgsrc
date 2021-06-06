# $NetBSD: Makefile,v 1.4 2021/06/06 07:53:48 mef Exp $

R_PKGNAME=	maptools
R_PKGVER=	1.1-1
CATEGORIES=	geography

MAINTAINER=	wen@NetBSD.org
COMMENT=	Tools for handling spatial objects
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-sp>=1.0.11:../../math/R-sp

# Packages suggested but not available:
#  'spatstat.geom', 'PBSmapping', 'raster', 'polyclip',
# 'plotrix', 'spatstat.linnet', 'spatstat.utils', 'spatstat'
TEST_DEPENDS+=	R-rgeos-[0-9]*:../../geography/R-rgeos

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
