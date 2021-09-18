# $NetBSD: Makefile,v 1.4 2021/09/18 11:30:32 mef Exp $

R_PKGNAME=	rstudioapi
R_PKGVER=	0.13

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Safely access the RStudio API
LICENSE=	mit

TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-clipr-[0-9]*:../../devel/R-clipr

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
