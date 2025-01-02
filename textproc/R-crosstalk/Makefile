# $NetBSD: Makefile,v 1.5 2025/01/02 08:40:55 mef Exp $

R_PKGNAME=	crosstalk
R_PKGVER=	1.2.1
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Inter-Widget Interactivity for HTML Widgets
LICENSE=	mit	# + file LICENSE

DEPENDS+=	R-lazyeval>=0.2.2:../../devel/R-lazyeval
DEPENDS+=	R-htmltools>=0.3.5:../../textproc/R-htmltools
DEPENDS+=	R-jsonlite>=1.6:../../textproc/R-jsonlite
DEPENDS+=	R-R6-[0-9]*:../../devel/R-R6

TEST_DEPENDS+=	R-shiny>=0.11:../../www/R-shiny
TEST_DEPENDS+=	R-ggplot2>=3.2.0:../../graphics/R-ggplot2
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
