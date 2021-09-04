# $NetBSD: Makefile,v 1.2 2021/09/04 11:51:19 mef Exp $

R_PKGNAME=	crosstalk
R_PKGVER=	1.1.1
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Inter-Widget Interactivity for HTML Widgets
LICENSE=	mit	# + file LICENSE

DEPENDS+=	R-lazyeval>=0.2.2:../../devel/R-lazyeval
DEPENDS+=	R-htmltools>=0.3.5:../../textproc/R-htmltools
DEPENDS+=	R-jsonlite>=1.6:../../textproc/R-jsonlite

TEST_DEPENDS+=	R-shiny>=0.11:../../www/R-shiny
TEST_DEPENDS+=	R-ggplot2>=3.2.0:../../graphics/R-ggplot2

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
