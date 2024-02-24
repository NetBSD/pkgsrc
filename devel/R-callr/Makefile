# $NetBSD: Makefile,v 1.11 2024/02/24 23:43:28 mef Exp $

R_PKGNAME=	callr
R_PKGVER=	3.7.5
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Call R from R
LICENSE=	mit

DEPENDS+=	R-processx>=3.8.2:../../sysutils/R-processx

# Package suggested but not available: 'asciicast'

TEST_DEPENDS+=	R-cliapp-[0-9]*:../../devel/R-cliapp
TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-crayon-[0-9]*:../../devel/R-crayon
TEST_DEPENDS+=	R-fansi-[0-9]*:../../devel/R-fansi
TEST_DEPENDS+=	R-pingr-[0-9]*:../../net/R-pingr
TEST_DEPENDS+=	R-ps-[0-9]*:../../sysutils/R-ps
TEST_DEPENDS+=	R-withr-[0-9]*:../../devel/R-withr
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-rprojroot-[0-9]*:../../devel/R-rprojroot
TEST_DEPENDS+=	R-spelling-[0-9]*:../../textproc/R-spelling
TEST_DEPENDS+=	R-tibble-[0-9]*:../../math/R-tibble
TEST_DEPENDS+=	R-markdown-[0-9]*:../../textproc/R-markdown
TEST_DEPENDS+=	R-mockery-[0-9]*:../../devel/R-mockery

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
