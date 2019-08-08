# $NetBSD: Makefile,v 1.2 2019/08/08 19:53:43 brook Exp $

R_PKGNAME=	viridis
R_PKGVER=	0.5.1
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Default color maps from 'matplotlib'
LICENSE=	mit

DEPENDS+=	R-ggplot2>=1.0.1:../../graphics/R-ggplot2
DEPENDS+=	R-viridisLite>=0.3.0:../../graphics/R-viridisLite

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
