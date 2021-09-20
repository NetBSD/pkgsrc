# $NetBSD: Makefile,v 1.1 2021/09/20 10:45:32 mef Exp $

R_PKGNAME=	spatstat.linnet
R_PKGVER=	2.3-0
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linear Networks Functionality of the 'spatstat' Family
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-spatstat.core>=2.3.0:../../geography/R-spatstat.core
DEPENDS+=	R-spatstat.data>=2.1.0:../../geography/R-spatstat.data
DEPENDS+=	R-spatstat.geom>=2.2.2:../../geography/R-spatstat.geom
DEPENDS+=	R-spatstat.utils>=2.2.0:../../geography/R-spatstat.utils

# Packages suggested but not available: 'locfit', 'spatstat'

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
