# $NetBSD: Makefile,v 1.6 2026/06/07 02:34:48 mef Exp $

R_PKGNAME=	promises
R_PKGVER=	1.5.0
CATEGORIES=	parallel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Abstractions for promise-based asynchronous programming
LICENSE=	mit

DEPENDS+=	R-fastmap-[0-9]*:../../devel/R-fastmap
DEPENDS+=	R-lifecycle-[0-9]*:../../devel/R-lifecycle
DEPENDS+=	R-magrittr>=1.5:../../devel/R-magrittr
DEPENDS+=	R-otel-[0-9]*:../../devel/R-otel
DEPENDS+=	R-rlang>=0.4.0:../../devel/R-rlang
DEPENDS+=	R-R6-[0-9]*:../../devel/R-R6

# Packages suggested but not available: 'future', 'vembedr'

TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
#EST_DEPENDS+=	R-future-[0-9]*:../../devel/R-future
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-purrr-[0-9]*:../../devel/R-purrr
#EST_DEPENDS+=	R-vembedr-[0-9]*:../../devel/R-vembedr
TEST_DEPENDS+=	R-spelling-[0-9]*:../../textproc/R-spelling

USE_LANGUAGES=	c c++

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != SunOS
pre-configure:
	${CP} ${FILESDIR}/Makevars ${WRKSRC}/src
.endif

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../sysutils/R-later/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
