# $NetBSD: Makefile,v 1.1 2020/08/01 02:24:00 brook Exp $

R_PKGNAME=	ggthemes
R_PKGVER=	4.2.0
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Extra Themes, Scales and Geoms for 'ggplot2'
LICENSE=	gnu-gpl-v2

DEPENDS+=	R-purrr>=0.3.3:../../devel/R-purrr
DEPENDS+=	R-ggplot2>=3.0.0:../../graphics/R-ggplot2
DEPENDS+=	R-scales>=1.1.0:../../graphics/R-scales
DEPENDS+=	R-tibble>=2.1.3:../../math/R-tibble
DEPENDS+=	R-stringr>=1.4.0:../../textproc/R-stringr

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
