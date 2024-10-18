# $NetBSD: Makefile,v 1.1 2024/10/18 23:12:40 mef Exp $

R_PKGNAME=	pkgsearch
R_PKGVER=	3.1.3
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Search and Query CRAN R Packages
LICENSE=	mit	# + file LICENSE

DEPENDS+=	R-jsonlite>=1.8.7:../../textproc/R-jsonlite
DEPENDS+=	R-curl>=5.0.0nb4:../../www/R-curl

# Package suggested but not available: 'shinyWidgets'

TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-memoise-[0-9]*:../../devel/R-memoise
TEST_DEPENDS+=	R-mockery-[0-9]*:../../devel/R-mockery
TEST_DEPENDS+=	R-pillar-[0-9]*:../../misc/R-pillar
TEST_DEPENDS+=	R-pingr-[0-9]*:../../net/R-pingr
TEST_DEPENDS+=	R-rstudioapi-[0-9]*:../../math/R-rstudioapi
TEST_DEPENDS+=	R-shiny-[0-9]*:../../www/R-shiny
TEST_DEPENDS+=	R-shinyjs-[0-9]*:../../www/R-shinyjs
#EST_DEPENDS+=	R-shinyWidgets-[0-9]*:
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-whoami-[0-9]*:../../devel/R-whoami
TEST_DEPENDS+=	R-withr-[0-9]*:../../devel/R-withr


USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
