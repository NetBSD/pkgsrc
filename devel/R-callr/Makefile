# $NetBSD: Makefile,v 1.4 2020/07/31 15:19:37 mef Exp $

R_PKGNAME=	callr
R_PKGVER=	3.4.3
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Call R from R
LICENSE=	mit

DEPENDS+=	R-processx>=3.4.0:../../sysutils/R-processx

# Packages suggested but not available:
#  'pingr', 'spelling'
TEST_DEPENDS+=	R-cliapp-[0-9]*:../../devel/R-cliapp
TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-crayon-[0-9]*:../../devel/R-crayon
TEST_DEPENDS+=	R-fansi-[0-9]*:../../devel/R-fansi
TEST_DEPENDS+=	R-withr-[0-9]*:../../devel/R-withr
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-rprojroot-[0-9]*:../../devel/R-rprojroot
TEST_DEPENDS+=	R-tibble-[0-9]*:../../math/R-tibble
TEST_DEPENDS+=	R-markdown-[0-9]*:../../textproc/R-markdown

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
