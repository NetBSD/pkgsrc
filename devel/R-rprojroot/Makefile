# $NetBSD: Makefile,v 1.4 2022/04/30 05:31:13 mef Exp $

R_PKGNAME=	rprojroot
R_PKGVER=	2.0.3
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Finding files in project subdirectories
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-backports>=1.1.4:../../math/R-backports

TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-mockr-[0-9]*:../../devel/R-mockr
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-withr-[0-9]*:../../devel/R-withr
TEST_DEPENDS+=	R-lifecycle-[0-9]*:../../devel/R-lifecycle

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
