# $NetBSD: Makefile,v 1.3 2022/04/29 04:18:39 mef Exp $

R_PKGNAME=	mockery
R_PKGVER=	0.4.3
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Mocking Library for R
LICENSE=	mit	# + file LICENSE

DEPENDS+=	R-testthat>=2.2.1:../../devel/R-testthat

TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
