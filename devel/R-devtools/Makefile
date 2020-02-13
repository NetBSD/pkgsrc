# $NetBSD: Makefile,v 1.4 2020/02/13 13:22:52 mef Exp $

R_PKGNAME=	devtools
R_PKGVER=	2.2.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Tools to make developing R packages easier
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-callr>=3.3.1:../../devel/R-callr
DEPENDS+=	R-cli>=1.1.0:../../devel/R-cli
DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
DEPENDS+=	R-git2r>=0.23.0:../../devel/R-git2r
DEPENDS+=	R-memoise>=1.0.0:../../devel/R-memoise
DEPENDS+=	R-pkgbuild>=1.0.3:../../devel/R-pkgbuild
DEPENDS+=	R-pkgload>=1.0.2:../../devel/R-pkgload
DEPENDS+=	R-rcmdcheck>=1.3.3:../../devel/R-rcmdcheck
DEPENDS+=	R-remotes>=2.1.0:../../devel/R-remotes
DEPENDS+=	R-roxygen2>=6.1.1:../../devel/R-roxygen2
DEPENDS+=	R-sessioninfo>=1.1.1:../../devel/R-sessioninfo
DEPENDS+=	R-testthat>=2.1.1:../../devel/R-testthat
DEPENDS+=	R-usethis>=1.5.0:../../devel/R-usethis
DEPENDS+=	R-withr>=2.1.2:../../devel/R-withr
DEPENDS+=	R-rstudioapi>=0.7:../../math/R-rstudioapi
DEPENDS+=	R-ellipsis>=0.3.0:../../math/R-ellipsis
DEPENDS+=	R-digest>=0.6.20:../../security/R-digest
DEPENDS+=	R-jsonlite>=1.6:../../textproc/R-jsonlite
DEPENDS+=	R-DT-[0-9]*:../../textproc/R-DT
DEPENDS+=	R-httr>=0.4:../../www/R-httr
DEPENDS+=	R-rversions-[0-9]*:../../devel/R-rversions

# Packages suggested but not available:
#  'BiocManager', 'foghorn', 'gmailr', 'pingr', 'pkgdown', 'rhub',
#  'spelling'
#
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-mockery-[0-9]*:../../devel/R-mockery
TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-bitops-[0-9]*:../../math/R-bitops
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-rversions-[0-9]*:../../devel/R-rversions
TEST_DEPENDS+=	R-lintr-[0-9]*:../../devel/R-lintr


USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
