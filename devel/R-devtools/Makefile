# $NetBSD: Makefile,v 1.14 2022/04/18 14:50:03 mef Exp $

R_PKGNAME=	devtools
R_PKGVER=	2.4.3
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Tools to make developing R packages easier
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-callr>=3.6.0:../../devel/R-callr
DEPENDS+=	R-cli>=3.0.0:../../devel/R-cli
DEPENDS+=	R-covr>=3.5.1:../../devel/R-covr
DEPENDS+=	R-desc>=1.3.0:../../devel/R-desc
DEPENDS+=	R-ellipsis>=0.3.1:../../math/R-ellipsis
DEPENDS+=	R-git2r>=0.23.0:../../devel/R-git2r
DEPENDS+=	R-memoise>=2.0.0:../../devel/R-memoise
DEPENDS+=	R-pkgbuild>=1.1.0:../../devel/R-pkgbuild
DEPENDS+=	R-pkgload>=1.1.0:../../devel/R-pkgload
DEPENDS+=	R-rcmdcheck>=1.3.3:../../devel/R-rcmdcheck
DEPENDS+=	R-remotes>=2.3.0:../../devel/R-remotes
DEPENDS+=	R-roxygen2>=7.1.1:../../devel/R-roxygen2
DEPENDS+=	R-sessioninfo>=1.1.1:../../devel/R-sessioninfo
DEPENDS+=	R-testthat>=2.3.2:../../devel/R-testthat
DEPENDS+=	R-usethis>=2.0.1:../../devel/R-usethis
DEPENDS+=	R-withr>=2.2.0:../../devel/R-withr
DEPENDS+=	R-rstudioapi>=0.11:../../math/R-rstudioapi
DEPENDS+=	R-digest>=0.6.20:../../security/R-digest
DEPENDS+=	R-jsonlite>=1.7.1:../../textproc/R-jsonlite
DEPENDS+=	R-DT>=0.15:../../textproc/R-DT
DEPENDS+=	R-httr>=1.4.2:../../www/R-httr
DEPENDS+=	R-rversions>=2.0.2:../../devel/R-rversions

# Packages suggested but not available:
#  'BiocManager', 'foghorn', 'gmailr', 'pkgdown', 'rhub'
#
# Packages required and available but unsuitable versions:
#  'rstudioapi', 'digest', 'DT', 'gh', 'spelling'

TEST_DEPENDS+=	R-bitops-[0-9]*:../../math/R-bitops
TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-curl>=4.3:../../www/R-curl
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-lintr>=2.0.1:../../devel/R-lintr
TEST_DEPENDS+=	R-mockery-[0-9]*:../../devel/R-mockery
TEST_DEPENDS+=	R-pingr-[0-9]*:../../net/R-pingr
TEST_DEPENDS+=	R-rmarkdown>=2.7:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-spelling>=2.1:../../textproc/R-spelling
TEST_DEPENDS+=	R-testthat>=2.3.2:../../devel/R-testthat
TEST_DEPENDS+=	R-usethis-[0-9]*:../../devel/R-usethis

#Packages required and available but unsuitable versions:
#  'desc', 'lifecycle', 'memoise', 'pkgload', 'remotes', 'rstudioapi',
#  'digest', 'DT', 'gh', 'knitr', 'rmarkdown', 'spelling'


USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
