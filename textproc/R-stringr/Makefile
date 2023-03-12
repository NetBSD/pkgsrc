# $NetBSD: Makefile,v 1.9 2023/03/12 08:54:41 mef Exp $

R_PKGNAME=	stringr
R_PKGVER=	1.5.0
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Simple, consistent wrappers for common string operations
LICENSE=	gnu-gpl-v2

DEPENDS+=	R-cli-[0-9]*:../../devel/R-cli
DEPENDS+=	R-glue>=1.2.0:../../devel/R-glue
DEPENDS+=	R-lifecycle-[0-9]*:../../devel/R-lifecycle
DEPENDS+=	R-magrittr>=1.5:../../devel/R-magrittr
DEPENDS+=	R-rlang-[0-9]*:../../devel/R-rlang
DEPENDS+=	R-stringi>=1.1.7:../../textproc/R-stringi
DEPENDS+=	R-vctrs-[0-9]*:../../math/R-vctrs

TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
