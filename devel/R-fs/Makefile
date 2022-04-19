# $NetBSD: Makefile,v 1.3 2022/04/19 12:46:05 mef Exp $

R_PKGNAME=	fs
R_PKGVER=	1.5.2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Cross-platform file system operations based on 'libuv'
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-tibble-[0-9]*:../../math/R-tibble
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-vctrs-[0-9]*:../../math/R-vctrs
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-spelling-[0-9]*:../../textproc/R-spelling

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
