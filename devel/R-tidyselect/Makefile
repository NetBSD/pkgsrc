# $NetBSD: Makefile,v 1.4 2022/04/30 09:41:57 mef Exp $

R_PKGNAME=	tidyselect
R_PKGVER=	1.1.2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Select from a set of strings
LICENSE=	mit

DEPENDS+=	R-glue>=1.3.0:../../devel/R-glue
DEPENDS+=	R-purrr>=0.3.2:../../devel/R-purrr
DEPENDS+=	R-rlang>=0.4.6:../../devel/R-rlang
DEPENDS+=	R-ellipsis>=0.3.0:../../math/R-ellipsis
DEPENDS+=	R-vctrs>=0.2.2:../../math/R-vctrs

TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-dplyr-[0-9]*:../../math/R-dplyr
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-withr-[0-9]*:../../devel/R-withr

USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
