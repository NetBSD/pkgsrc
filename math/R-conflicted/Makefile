# $NetBSD: Makefile,v 1.1 2024/01/21 10:03:12 mef Exp $

R_PKGNAME=	conflicted
R_PKGVER=	1.2.0

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Alternative Conflict Resolution Strategy
LICENSE=	mit	# + file LICENSE

DEPENDS+=	R-memoise>=2.0.1:../../devel/R-memoise
DEPENDS+=	R-rlang>=1.0.0:../../devel/R-rlang

TEST_DEPENDS+=	R-callr-[0-9]*:../../devel/R-callr
TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-dplyr-[0-9]*:../../math/R-dplyr
TEST_DEPENDS+=	R-pkgload-[0-9]*:../../devel/R-pkgload
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-withr-[0-9]*:../../devel/R-withr

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../devel/R-cli/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
