# $NetBSD: Makefile,v 1.1 2024/10/18 23:03:23 mef Exp $

R_PKGNAME=	pkgdepends
R_PKGVER=	0.8.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Package Dependency Resolution and Downloads
LICENSE=	mit	# + file LICENSE

DEPENDS+=	R-zip>=2.3.0:../../archivers/R-zip
DEPENDS+=	R-callr>=3.3.1:../../devel/R-callr
DEPENDS+=	R-desc>=1.4.3:../../devel/R-desc
DEPENDS+=	R-filelock>=1.0.2:../../devel/R-filelock
DEPENDS+=	R-lpSolve>=5.6.21:../../devel/R-lpSolve
DEPENDS+=	R-pkgbuild>=1.0.2:../../devel/R-pkgbuild
DEPENDS+=	R-pkgcache>=2.2.0:../../devel/R-pkgcache
DEPENDS+=	R-processx>=3.4.2:../../sysutils/R-processx
DEPENDS+=	R-ps>=1.7.7:../../sysutils/R-ps
DEPENDS+=	R-jsonlite>=1.8.7:../../textproc/R-jsonlite
DEPENDS+=	R-curl>=5.0.0nb4:../../www/R-curl

# Packages suggested but not available: 'asciicast', 'svglite'

# TEST_DEPENDS+=R-asciicast-[0-9]*:
TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-debugme-[0-9]*:../../devel/R-debugme
TEST_DEPENDS+=	R-fs-[0-9]*:../../devel/R-fs
TEST_DEPENDS+=	R-gh-[0-9]*:../../www/R-gh
TEST_DEPENDS+=	R-gitcreds-[0-9]*:../../security/R-gitcreds
TEST_DEPENDS+=	R-htmlwidgets-[0-9]*:../../www/R-htmlwidgets
TEST_DEPENDS+=	R-mockery-[0-9]*:../../devel/R-mockery
TEST_DEPENDS+=	R-pak-[0-9]*:../../devel/R-pak
TEST_DEPENDS+=	R-pingr-[0-9]*:../../net/R-pingr
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-rstudioapi-[0-9]*:../../math/R-rstudioapi
TEST_DEPENDS+=	R-spelling-[0-9]*:../../textproc/R-spelling
#EST_DEPENDS+=	R-svglite-[0-9]*:
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-webfakes-[0-9]*:../../www/R-webfakes

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../devel/R-cli/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
