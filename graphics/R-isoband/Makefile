# $NetBSD: Makefile,v 1.1 2021/06/06 06:50:17 mef Exp $

R_PKGNAME=	isoband
R_PKGVER=	0.2.4
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Generate Isolines and Isobands from Regularly Spaced Elevation Grids
LICENSE=	mit	# + file LICENSE

# Packages suggested but not available:
#  'magick'
TEST_DEPENDS+=	R-ggplot2-[0-9]*:../../graphics/R-ggplot2
#EST_DEPENDS+=	R-magick-[0-9]*:../../graphics/R-magick
TEST_DEPENDS+=	R-microbenchmark-[0-9]*:../../benchmarks/R-microbenchmark
TEST_DEPENDS+=	R-sf-[0-9]*:../../geography/R-sf

USE_LANGUAGES=	c++

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
