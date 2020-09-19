# $NetBSD: Makefile,v 1.2 2020/09/19 21:39:43 mef Exp $

R_PKGNAME=	fs
R_PKGVER=	1.5.0
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

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
