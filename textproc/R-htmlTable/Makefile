# $NetBSD: Makefile,v 1.2 2019/08/08 19:53:56 brook Exp $

R_PKGNAME=	htmlTable
R_PKGVER=	1.13.1
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Advanced tables for Markdown/HTML
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-checkmate>=1.9.4:../../devel/R-checkmate
DEPENDS+=	R-magrittr>=1.5:../../devel/R-magrittr
DEPENDS+=	R-rstudioapi>=0.6:../../math/R-rstudioapi
DEPENDS+=	R-knitr>=1.6:../../print/R-knitr
DEPENDS+=	R-htmltools>=0.3.6:../../textproc/R-htmltools
DEPENDS+=	R-stringr>=1.4.0:../../textproc/R-stringr
DEPENDS+=	R-htmlwidgets>=1.3:../../www/R-htmlwidgets

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
