# $NetBSD: Makefile,v 1.4 2022/04/30 14:39:03 mef Exp $

R_PKGNAME=	roxygen2
R_PKGVER=	7.1.2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	In-line documentation for R
LICENSE=	mit

DEPENDS+=	R-desc>=1.2.0:../../devel/R-desc
DEPENDS+=	R-pkgload>=1.0.2:../../devel/R-pkgload
DEPENDS+=	R-purrr>=0.3.2:../../devel/R-purrr
DEPENDS+=	R-digest>=0.6.20:../../security/R-digest
DEPENDS+=	R-brew>=1.0.6:../../textproc/R-brew
DEPENDS+=	R-commonmark>=1.7:../../textproc/R-commonmark
DEPENDS+=	R-stringi>=1.4.3:../../textproc/R-stringi
DEPENDS+=	R-stringr>=1.0.0:../../textproc/R-stringr
DEPENDS+=	R-xml2>=1.2.2:../../textproc/R-xml2
DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr

#  Packages suggested but not available: 'R.methodsS3', 'R.oo'
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-devtools-[0-9]*:../../devel/R-devtools

USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../lang/R-cpp11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
