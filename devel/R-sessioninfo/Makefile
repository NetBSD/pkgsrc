# $NetBSD: Makefile,v 1.2 2022/04/30 08:40:06 mef Exp $

R_PKGNAME=	sessioninfo
R_PKGVER=	1.2.2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	R session information
LICENSE=	gnu-gpl-v2

DEPENDS+=	R-cli>=1.1.0:../../devel/R-cli
DEPENDS+=	R-withr>=2.1.2:../../devel/R-withr

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
TEST_DEPENDS+=	R-callr-[0-9]*:../../devel/R-callr
TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-mockery-[0-9]*:../../devel/R-mockery
#TEST_DEPENDS+=	R-reticulate-[0-9]*:
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
