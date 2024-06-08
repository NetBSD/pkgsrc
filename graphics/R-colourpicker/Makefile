# $NetBSD: Makefile,v 1.3 2024/06/08 13:09:53 mef Exp $

R_PKGNAME=	colourpicker
R_PKGVER=	1.3.0
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Colour picker tool for Shiny and for selecting colours in plots
LICENSE=	mit

DEPENDS+=	R-ggplot2>=3.2.0:../../graphics/R-ggplot2
DEPENDS+=	R-htmltools>=0.3.6:../../textproc/R-htmltools
DEPENDS+=	R-jsonlite>=1.6:../../textproc/R-jsonlite
DEPENDS+=	R-htmlwidgets>=0.7:../../www/R-htmlwidgets
DEPENDS+=	R-miniUI>=0.1.1:../../www/R-miniUI
DEPENDS+=	R-shiny>=1.8.1.1:../../www/R-shiny
DEPENDS+=	R-shinyjs>=1.0:../../www/R-shinyjs

USE_LANGUAGES=	# none

# Package suggested but not available: 'shinydisconnect'

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
