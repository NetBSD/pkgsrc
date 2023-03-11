# $NetBSD: Makefile,v 1.2 2023/03/11 11:29:06 mef Exp $

R_PKGNAME=	mockr
R_PKGVER=	0.2.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Mocking in R
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-rlang>=1.0.2:../../devel/R-rlang
DEPENDS+=	R-withr>=2.5.0:../../devel/R-withr

TEST_DEPENDS+=	R-fs-[0-9]*:../../devel/R-fs
TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-pkgload-[0-9]*:../../devel/R-pkgload
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-usethis-[0-9]*:../../devel/R-usethis

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
