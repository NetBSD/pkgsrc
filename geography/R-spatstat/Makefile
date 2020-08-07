# $NetBSD: Makefile,v 1.1 2020/08/07 03:55:17 brook Exp $

R_PKGNAME=	spatstat
R_PKGVER=	1.63-2
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Spatial Point Pattern Analysis, Model-Fitting, Simulation, Tests
LICENSE=	gnu-gpl-v2

USE_LANGUAGES+=	c c++

DEPENDS+=	R-deldir>=0.0.21:../../geography/R-deldir
DEPENDS+=	R-spatstat.data>=1.4.3:../../geography/R-spatstat.data
DEPENDS+=	R-spatstat.utils>=1.17.0:../../geography/R-spatstat.utils
DEPENDS+=	R-abind>=1.4.0:../../math/R-abind
DEPENDS+=	R-goftest>=1.0.3:../../math/R-goftest
DEPENDS+=	R-polyclip>=1.5.0:../../graphics/R-polyclip
DEPENDS+=	R-tensor>=1.5:../../math/R-tensor

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
