# $NetBSD: Makefile,v 1.3 2022/04/30 01:55:53 mef Exp $

R_PKGNAME=	rex
R_PKGVER=	1.2.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Friendly Regular Expressions
LICENSE=	mit	# + file LICENSE

DEPENDS+=	R-lazyeval>=0.2.2:../../devel/R-lazyeval
DEPENDS+=	R-magrittr>=1.5:../../devel/R-magrittr

TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-dplyr-[0-9]*:../../math/R-dplyr
TEST_DEPENDS+=	R-ggplot2-[0-9]*:../../graphics/R-ggplot2
TEST_DEPENDS+=	R-Hmisc-[0-9]*:../../misc/R-Hmisc
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-roxygen2-[0-9]*:../../devel/R-roxygen2
TEST_DEPENDS+=	R-rvest-[0-9]*:../../www/R-rvest
TEST_DEPENDS+=	R-stringr-[0-9]*:../../textproc/R-stringr
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
