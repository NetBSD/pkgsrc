# $NetBSD: Makefile,v 1.6 2024/12/02 09:24:06 jperkin Exp $

R_PKGNAME=	spatstat
R_PKGVER=	3.3-0
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Spatial Point Pattern Analysis, Model-Fitting, Simulation, Tests
LICENSE=	gnu-gpl-v2

USE_LANGUAGES+=	c c++

DEPENDS+=	R-deldir>=0.0.21:../../geography/R-deldir
DEPENDS+=	R-deldir>=0.0.21:../../geography/R-deldir
DEPENDS+=	R-spatstat.data>=2.1.0:../../geography/R-spatstat.data
DEPENDS+=	R-spatstat.geom>=2.1.0:../../geography/R-spatstat.geom
DEPENDS+=	R-spatstat.linnet>=3.2.2:../../geography/R-spatstat.linnet
DEPENDS+=	R-spatstat.model-[0-9]*:../../geography/R-spatstat.model
#DEPENDS+=	R-spatstat.univar-[0-9]*:../../geography/R-spatstat.univar
DEPENDS+=	R-spatstat.utils>=2.1.0:../../geography/R-spatstat.utils
DEPENDS+=	R-abind>=1.4.0:../../math/R-abind
DEPENDS+=	R-goftest>=1.0.3:../../math/R-goftest
DEPENDS+=	R-polyclip>=1.5.0:../../graphics/R-polyclip
DEPENDS+=	R-tensor>=1.5:../../math/R-tensor

TEST_DEPENDS+=	tex-anysize-[0-9]*:../../print/tex-anysize
TEST_DEPENDS+=	tex-geometry-[0-9]*:../../print/tex-geometry
# pdfTeX error: pdflatex (file tctt1000): Font tctt1000 at 600 not found
#  -- not resolved
#EST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
