# $NetBSD: Makefile,v 1.2 2021/09/20 03:11:38 mef Exp $

R_PKGNAME=	manipulateWidget
R_PKGVER=	0.11.0
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Add Even More Interactivity to Interactive Charts
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3	# OR file LICENSE

DEPENDS+=	R-base64enc>=0.1.3:../../converters/R-base64enc
DEPENDS+=	R-knitr>=1.23:../../print/R-knitr
DEPENDS+=	R-htmltools>=0.3.6:../../textproc/R-htmltools
DEPENDS+=	R-htmlwidgets>=1.3:../../www/R-htmlwidgets
DEPENDS+=	R-miniUI>=0.1.1.1:../../www/R-miniUI
DEPENDS+=	R-shiny>=1.0.3:../../www/R-shiny
DEPENDS+=	R-miniUI-[0-9]*:../../www/R-miniUI
DEPENDS+=	R-webshot-[0-9]*:../../www/R-webshot
DEPENDS+=	R-shinyjs-[0-9]*:../../www/R-shinyjs

#Packages suggested but not available:
#  'dygraphs', 'leaflet', 'plotly'
TEST_DEPENDS+=	R-xts-[0-9]*:../../math/R-xts
TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
