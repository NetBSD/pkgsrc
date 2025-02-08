# $NetBSD: Makefile,v 1.4 2025/02/08 09:25:44 mef Exp $

R_PKGNAME=	spatstat.linnet
R_PKGVER=	3.2-5
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linear Networks Functionality of the 'spatstat' Family
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-spatstat.data>=3.0:../../geography/R-spatstat.data
DEPENDS+=	R-spatstat.explore>=3.2.5:../../geography/R-spatstat.explore
DEPENDS+=	R-spatstat.geom>=3.2.7:../../geography/R-spatstat.geom
DEPENDS+=	R-spatstat.model>=3.2.8:../../geography/R-spatstat.model
DEPENDS+=	R-spatstat.random>=3.2.1:../../geography/R-spatstat.random
DEPENDS+=	R-spatstat.utils>=2.2.0:../../geography/R-spatstat.utils

# Packages suggested but not available: 'locfit'
TEST_DEPENDS+=	R-spatstat-[0-9]*:../../geography/R-spatstat

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
