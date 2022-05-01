# $NetBSD: Makefile,v 1.2 2022/05/01 23:31:07 mef Exp $

R_PKGNAME=	wk
R_PKGVER=	0.6.0
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Lightweight well-known geometry parsing
LICENSE=	mit

TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-vctrs-[0-9]*:../../math/R-vctrs
TEST_DEPENDS+=	R-sf-[0-9]*:../../geography/R-sf
TEST_DEPENDS+=	R-tibble-[0-9]*:../../math/R-tibble
TEST_DEPENDS+=	R-readr-[0-9]*:../../textproc/R-readr

USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../lang/R-cpp11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
