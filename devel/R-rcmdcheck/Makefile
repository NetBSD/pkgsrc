# $NetBSD: Makefile,v 1.2 2022/04/29 13:52:36 mef Exp $

R_PKGNAME=	rcmdcheck
R_PKGVER=	1.4.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Run 'R CMD check' from 'R' and capture results
LICENSE=	mit

DEPENDS+=	R-callr>=3.1.1.9000:../../devel/R-callr
DEPENDS+=	R-cli>=1.1.0:../../devel/R-cli
DEPENDS+=	R-crayon>=1.3.4:../../devel/R-crayon
DEPENDS+=	R-desc>=1.2.0:../../devel/R-desc
DEPENDS+=	R-pkgbuild>=1.0.4:../../devel/R-pkgbuild
DEPENDS+=	R-rprojroot>=1.3.2:../../devel/R-rprojroot
DEPENDS+=	R-sessioninfo>=1.1.1:../../devel/R-sessioninfo
DEPENDS+=	R-withr>=2.1.2:../../devel/R-withr
DEPENDS+=	R-prettyunits>=1.0.2:../../math/R-prettyunits
DEPENDS+=	R-digest>=0.6.20:../../security/R-digest
DEPENDS+=	R-xopen>=1.0.0:../../sysutils/R-xopen
DEPENDS+=	R-curl-[0-9]*:../../www/R-curl

# Packages suggested but not available: 'svglite', 'webfakes'
TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-mockery-[0-9]*:../../devel/R-mockery
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
