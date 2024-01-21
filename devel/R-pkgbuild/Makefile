# $NetBSD: Makefile,v 1.9 2024/01/21 23:20:28 mef Exp $

R_PKGNAME=	pkgbuild
R_PKGVER=	1.4.3
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Find tools needed to build R packages
LICENSE=	mit

DEPENDS+=	R-callr>=3.2.0:../../devel/R-callr
DEPENDS+=	R-cli>=1.1.0:../../devel/R-cli
DEPENDS+=	R-desc>=1.2.0:../../devel/R-desc
DEPENDS+=	R-withr>=2.1.2:../../devel/R-withr

TEST_DEPENDS+=	R-cpp11-[0-9]*:../../lang/R-cpp11
TEST_DEPENDS+=	R-Rcpp-[0-9]*:../../devel/R-Rcpp
TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-mockery-[0-9]*:../../devel/R-mockery
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

# need for make test
USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
