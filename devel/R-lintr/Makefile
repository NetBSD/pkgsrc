# $NetBSD: Makefile,v 1.5 2024/01/21 02:37:52 mef Exp $

R_PKGNAME=	lintr
R_PKGVER=	3.1.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	'Linter' for R Code
LICENSE=	mit	# + file LICENSE

DEPENDS+=	R-crayon>=1.3.4:../../devel/R-crayon
DEPENDS+=	R-cyclocomp-[0-9]*:../../devel/R-cyclocomp
DEPENDS+=	R-digest>=0.6.20:../../security/R-digest
DEPENDS+=	R-httr>=1.2.1:../../www/R-httr
DEPENDS+=	R-jsonlite>=1.6:../../textproc/R-jsonlite
DEPENDS+=	R-knitr>=1.23:../../print/R-knitr
DEPENDS+=	R-rex>=1.1.2:../../devel/R-rex
DEPENDS+=	R-rstudioapi>=0.2:../../math/R-rstudioapi
DEPENDS+=	R-stringdist-[0-9]*:../../math/R-stringdist
DEPENDS+=	R-testthat>=2.2.1:../../devel/R-testthat
DEPENDS+=	R-xml2>=1.0.0:../../textproc/R-xml2
DEPENDS+=	R-xmlparsedata>=1.0.5:../../textproc/R-xmlparsedata

# Packages suggested but not available: 'bookdown', 'tufte'

TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-mockery-[0-9]*:../../devel/R-mockery
TEST_DEPENDS+=	R-patrick-[0-9]*:../../devel/R-patrick
TEST_DEPENDS+=	R-pkgdown-[0-9]*:../../www/R-pkgdown
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
