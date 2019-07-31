# $NetBSD: Makefile,v 1.1 2019/07/31 13:01:17 brook Exp $

CATEGORIES=	graphics R

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/viridis/
COMMENT=	Default color maps from 'matplotlib'
LICENSE=	mit

R_PKGNAME=	viridis
R_PKGVER=	0.5.1

DEPENDS+=	R-ggplot2>=1.0.1:../../graphics/R-ggplot2
DEPENDS+=	R-viridisLite>=0.3.0:../../graphics/R-viridisLite

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
