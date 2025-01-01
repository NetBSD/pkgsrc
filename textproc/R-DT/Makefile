# $NetBSD: Makefile,v 1.7 2025/01/01 15:06:34 mef Exp $

R_PKGNAME=	DT
R_PKGVER=	0.33
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Wrapper of the JavaScript Library 'DataTables'
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-magrittr>=1.5:../../devel/R-magrittr
DEPENDS+=	R-promises>=1.0.1:../../parallel/R-promises
DEPENDS+=	R-htmltools>=0.3.6:../../textproc/R-htmltools
DEPENDS+=	R-jsonlite>=0.9.16:../../textproc/R-jsonlite
DEPENDS+=	R-htmlwidgets>=1.3:../../www/R-htmlwidgets
DEPENDS+=	R-httpuv-[0-9]*:../../www/R-httpuv
DEPENDS+=	R-crosstalk-[0-9]*:../../textproc/R-crosstalk
DEPENDS+=	R-jquerylib-[0-9]*:../../www/R-jquerylib

# Packages suggested but not available: 'future'

TEST_DEPENDS+=	R-R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
#EST_DEPENDS+=	R-future-[0-9]*:../../wip/R-future
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-shiny-[0-9]*:../../www/R-shiny
TEST_DEPENDS+=	R-testit-[0-9]*:../../devel/R-testit
TEST_DEPENDS+=	R-tibble-[0-9]*:../../math/R-tibble

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
