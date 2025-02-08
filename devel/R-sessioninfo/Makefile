# $NetBSD: Makefile,v 1.3 2025/02/08 07:45:45 mef Exp $

R_PKGNAME=	sessioninfo
R_PKGVER=	1.2.3
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	R session information
LICENSE=	gnu-gpl-v2

DEPENDS+=	R-cli>=1.1.0:../../devel/R-cli
DEPENDS+=	R-withr>=2.1.2:../../devel/R-withr

# Packages suggested but not available: 'gh', 'reticulate'

TEST_DEPENDS+=	R-callr-[0-9]*:../../devel/R-callr
TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-mockery-[0-9]*:../../devel/R-mockery
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
