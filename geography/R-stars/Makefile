# $NetBSD: Makefile,v 1.1 2020/08/09 15:24:46 brook Exp $

R_PKGNAME=	stars
R_PKGVER=	0.4-3
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Spatiotemporal Arrays, Raster and Vector Data Cubes
LICENSE=	apache-2.0

DEPENDS+=	R-rlang>=0.4.5:../../devel/R-rlang
DEPENDS+=	R-lwgeom>=0.2.5:../../geography/R-lwgeom
DEPENDS+=	R-sf>=0.9.0:../../geography/R-sf
DEPENDS+=	R-abind>=1.4.5:../../math/R-abind
DEPENDS+=	R-units>=0.6.5:../../math/R-units

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
