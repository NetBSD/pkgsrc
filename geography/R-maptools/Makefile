# $NetBSD: Makefile,v 1.8 2026/02/18 10:39:42 wiz Exp $

R_PKGNAME=	maptools
R_PKGVER=	1.1-7
PKGREVISION=	1
CATEGORIES=	geography

MAINTAINER=	wen@NetBSD.org
COMMENT=	Tools for handling spatial objects
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-sp>=1.0.11:../../math/R-sp

# Packages suggested but not available:
#   'spatstat.geom', 'PBSmapping', 'maps', 'RColorBrewer', 'raster',
#   'polyclip', 'plotrix', 'spatstat.linnet', 'spatstat.utils',
#   'spatstat'

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
