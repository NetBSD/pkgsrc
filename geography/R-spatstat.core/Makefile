# $NetBSD: Makefile,v 1.1 2021/09/20 10:38:59 mef Exp $

R_PKGNAME=	spatstat.core
R_PKGVER=	2.3-0
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Core Functionality of the 'spatstat' Family
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

# ERROR: dependencies 'spatstat.data', 'spatstat.geom', 'spatstat.utils', 'spatstat.sparse', 'abind', 'tensor', 'goftest' are not available for package 'spatst
DEPENDS+=	R-spatstat.data>=2.1.0:../../geography/R-spatstat.data
DEPENDS+=	R-spatstat.geom>=2.1.0:../../geography/R-spatstat.geom
DEPENDS+=	R-spatstat.utils>=2.2.0:../../geography/R-spatstat.utils
DEPENDS+=	R-spatstat.sparse>=2.0.0:../../geography/R-spatstat.sparse
DEPENDS+=	R-abind>=1.4.5:../../math/R-abind
DEPENDS+=	R-goftest>=1.2.2:../../math/R-goftest
DEPENDS+=	R-tensor>=1.5:../../math/R-tensor

# Packages suggested but not available:
#   'sm', 'maptools', 'gsl', 'locfit', 'RandomFields',
#   'RandomFieldsUtils', 'fftwtools', 'nleqslv', 'spatstat.linnet',
#   'spatstat'

USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
