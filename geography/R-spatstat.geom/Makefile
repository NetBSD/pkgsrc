# $NetBSD: Makefile,v 1.5 2024/12/02 13:09:33 mef Exp $

R_PKGNAME=	spatstat.geom
R_PKGVER=	3.3-4
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Geometrical Functionality of the 'spatstat' Family
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-deldir>=0.0.21:../../geography/R-deldir
DEPENDS+=	R-spatstat.data>=3.0:../../geography/R-spatstat.data
DEPENDS+=	R-spatstat.univar-[0-9]*:../../geography/R-spatstat.univar
DEPENDS+=	R-spatstat.utils>=2.2.0:../../geography/R-spatstat.utils
DEPENDS+=	R-polyclip>=1.10.0:../../graphics/R-polyclip

# Package suggested but not available: 'fftwtools'
TEST_DEPENDS+=	R-spatstat.random-[0-9]*:../../geography/R-spatstat.random
TEST_DEPENDS+=	R-spatstat.explore-[0-9]*:../../geography/R-spatstat.explore
TEST_DEPENDS+=	R-spatstat.model-[0-9]*:../../geography/R-spatstat.model
TEST_DEPENDS+=	R-spatstat.linnet-[0-9]*:../../geography/R-spatstat.linnet
TEST_DEPENDS+=	R-spatstat-[0-9]*:../../geography/R-spatstat

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
