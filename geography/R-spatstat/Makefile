# $NetBSD: Makefile,v 1.3 2021/09/20 12:25:34 mef Exp $

R_PKGNAME=	spatstat
R_PKGVER=	2.2-0
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Spatial Point Pattern Analysis, Model-Fitting, Simulation, Tests
LICENSE=	gnu-gpl-v2

USE_LANGUAGES+=	c c++

DEPENDS+=	R-deldir>=0.0.21:../../geography/R-deldir
DEPENDS+=	R-spatstat.core>=2.1.0:../../geography/R-spatstat.core
DEPENDS+=	R-spatstat.data>=2.1.0:../../geography/R-spatstat.data
DEPENDS+=	R-spatstat.geom>=2.1.0:../../geography/R-spatstat.geom
DEPENDS+=	R-spatstat.linnet>=2.1.0:../../geography/R-spatstat.linnet
DEPENDS+=	R-spatstat.utils>=2.1.0:../../geography/R-spatstat.utils
DEPENDS+=	R-abind>=1.4.0:../../math/R-abind
DEPENDS+=	R-goftest>=1.0.3:../../math/R-goftest
DEPENDS+=	R-polyclip>=1.5.0:../../graphics/R-polyclip
DEPENDS+=	R-tensor>=1.5:../../math/R-tensor

TEST_DEPENDS+=	tex-anysize-[0-9]*:../../print/tex-anysize

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
