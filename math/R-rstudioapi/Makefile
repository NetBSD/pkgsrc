# $NetBSD: Makefile,v 1.5 2023/06/08 16:09:11 mef Exp $

R_PKGNAME=	rstudioapi
R_PKGVER=	0.14

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
