# $NetBSD: Makefile,v 1.1 2021/09/20 08:50:34 mef Exp $

R_PKGNAME=	spatstat.geom
R_PKGVER=	2.2-2
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Geometrical Functionality of the 'spatstat' Family
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-deldir>=0.0.21:../../geography/R-deldir
DEPENDS+=	R-spatstat.data>=2.0:../../geography/R-spatstat.data
DEPENDS+=	R-spatstat.utils>=2.2.0:../../geography/R-spatstat.utils
DEPENDS+=	R-polyclip>=1.10.0:../../graphics/R-polyclip

# Packages suggested but not available:
#   'spatstat.core', 'spatstat.linnet', 'maptools', 'fftwtools',
#   'spatstat'

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
