# $NetBSD: Makefile,v 1.1 2024/11/24 09:33:00 mef Exp $

R_PKGNAME=	here
R_PKGVER=	1.0.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Simpler Way to Find Your Files
LICENSE=	mit	# + file LICENSE

DEPENDS+=	R-rprojroot>=2.0.2:../../devel/R-rprojroot

# Packages suggested but not available: 'covr', 'palmerpenguins'
TEST_DEPENDS+=	R-conflicted-[0-9]*:../../math/R-conflicted
TEST_DEPENDS+=	R-plyr-[0-9]*:../../math/R-plyr
TEST_DEPENDS+=	R-readr-[0-9]*:../../textproc/R-readr
TEST_DEPENDS+=	R-rlang-[0-9]*:../../devel/R-rlang
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-uuid-[0-9]*:../../devel/R-uuid
TEST_DEPENDS+=	R-withr-[0-9]*:../../devel/R-withr

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
