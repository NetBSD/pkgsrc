# $NetBSD: Makefile,v 1.3 2021/09/08 11:15:48 mef Exp $

R_PKGNAME=	htmlTable
R_PKGVER=	2.2.1
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

# Packages suggested but not available: 'reshape', 'lubridate'
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-XML-[0-9]*:../../math/R-XML
TEST_DEPENDS+=	R-xml2-[0-9]*:../../textproc/R-xml2
TEST_DEPENDS+=	R-Hmisc-[0-9]*:../../misc/R-Hmisc
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-chron-[0-9]*:../../math/R-chron
TEST_DEPENDS+=	R-tibble-[0-9]*:../../math/R-tibble
TEST_DEPENDS+=	R-tidyselect-[0-9]*:../../devel/R-tidyselect
TEST_DEPENDS+=	R-tidyr-[0-9]*:../../math/R-tidyr
TEST_DEPENDS+=	R-dplyr-[0-9]*:../../math/R-dplyr

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
