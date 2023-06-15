# $NetBSD: Makefile,v 1.7 2023/06/15 11:52:16 mef Exp $

R_PKGNAME=	latticeExtra
R_PKGVER=	0.6-30
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Extra graphical utilities based on lattice
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-RColorBrewer>=1.0.5:../../math/R-RColorBrewer
DEPENDS+=	R-jpeg-[0-9]*:../../graphics/R-jpeg
DEPENDS+=	R-png-[0-9]*:../../graphics/R-png
DEPENDS+=	R-interp-[0-9]*:../../graphics/R-interp

TEST_DEPENDS+=	R-maps-[0-9]*:../../geography/R-maps
TEST_DEPENDS+=	R-mapproj-[0-9]*:../../math/R-mapproj
TEST_DEPENDS+=	R-deldir-[0-9]*:../../geography/R-deldir
TEST_DEPENDS+=	R-quatreg-[0-9]*:../../math/R-quantreg
TEST_DEPENDS+=	R-zoo-[0-9]*:../../math/R-zoo

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
