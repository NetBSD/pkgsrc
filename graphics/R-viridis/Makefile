# $NetBSD: Makefile,v 1.4 2021/09/20 03:39:09 mef Exp $

R_PKGNAME=	viridis
R_PKGVER=	0.6.1
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Default color maps from 'matplotlib'
LICENSE=	mit

DEPENDS+=	R-ggplot2>=1.0.1:../../graphics/R-ggplot2
DEPENDS+=	R-gridExtra>=2.3:../../graphics/R-gridExtra
DEPENDS+=	R-viridisLite>=0.4.0:../../graphics/R-viridisLite

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
