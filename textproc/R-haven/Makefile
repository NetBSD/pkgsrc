# $NetBSD: Makefile,v 1.5 2024/06/05 12:13:51 mef Exp $

R_PKGNAME=	haven
R_PKGVER=	2.5.4
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Import and export 'SPSS', 'Stata' and 'SAS' files
LICENSE=	mit

DEPENDS+=	R-forcats>=0.2.0:../../math/R-forcats
DEPENDS+=	R-tibble>=2.1.3:../../math/R-tibble
DEPENDS+=	R-readr>=0.1.0:../../textproc/R-readr
DEPENDS+=	R-hms>=0.5.0:../../time/R-hms
DEPENDS+=	R-cpp11-[0-9]*:../../lang/R-cpp11
DEPENDS+=	R-tidyselect-[0-9]*:../../devel/R-tidyselect

TEST_DEPENDS+=	R-fs-[0-9]*:../../devel/R-fs
TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat

USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
