# $NetBSD: Makefile,v 1.3 2021/06/05 08:43:54 mef Exp $

R_PKGNAME=	promises
R_PKGVER=	1.2.0.1
CATEGORIES=	parallel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Abstractions for promise-based asynchronous programming
LICENSE=	mit

DEPENDS+=	R-magrittr>=1.5:../../devel/R-magrittr
DEPENDS+=	R-rlang>=0.4.0:../../devel/R-rlang
DEPENDS+=	R-R6-[0-9]*:../../devel/R-R6

TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
#EST_DEPENDS+=	R-future-[0-9]*:../../devel/R-future
TEST_DEPENDS+=	R-fastmap-[0-9]*:../../devel/R-fastmap
TEST_DEPENDS+=	R-purrr-[0-9]*:../../devel/R-purrr
#EST_DEPENDS+=	R-vembedr-[0-9]*:../../devel/R-vembedr
TEST_DEPENDS+=	R-spelling-[0-9]*:../../textproc/R-spelling

USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../sysutils/R-later/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
