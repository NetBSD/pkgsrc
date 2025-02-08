# $NetBSD: Makefile,v 1.8 2025/02/08 09:22:21 mef Exp $

R_PKGNAME=	spatstat
R_PKGVER=	3.3-1
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Spatial Point Pattern Analysis, Model-Fitting, Simulation, Tests
LICENSE=	gnu-gpl-v2

USE_LANGUAGES+=	c c++

DEPENDS+=	R-deldir>=0.0.21:../../geography/R-deldir
DEPENDS+=	R-spatstat.data>=2.1.0:../../geography/R-spatstat.data
DEPENDS+=	R-spatstat.geom>=2.1.0:../../geography/R-spatstat.geom
DEPENDS+=	R-spatstat.linnet>=3.2.2:../../geography/R-spatstat.linnet
DEPENDS+=	R-spatstat.model-[0-9]*:../../geography/R-spatstat.model
DEPENDS+=	R-spatstat.utils>=2.1.0:../../geography/R-spatstat.utils
DEPENDS+=	R-abind>=1.4.0:../../math/R-abind
DEPENDS+=	R-goftest>=1.0.3:../../math/R-goftest
DEPENDS+=	R-polyclip>=1.5.0:../../graphics/R-polyclip
DEPENDS+=	R-tensor>=1.5:../../math/R-tensor

# pdfTeX error: pdflatex (file tctt1000): Font tctt1000 at 600 not found

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-geometry-[0-9]*:../../print/tex-geometry
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
