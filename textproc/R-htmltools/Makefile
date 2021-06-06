# $NetBSD: Makefile,v 1.6 2021/06/06 23:48:13 mef Exp $

R_PKGNAME=	htmltools
R_PKGVER=	0.5.1.1
CATEGORIES=	textproc

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Tools for HTML
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-digest>=0.6.20:../../security/R-digest
DEPENDS+=	R-base64enc-[0-9]*:../../converters/R-base64enc
DEPENDS+=	R-rlang-[0-9]*:../../devel/R-rlang

# Packages suggested but not available:  'ragg'
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-Cairo-[0-9]*:../../graphics/R-Cairo
#EST_DEPENDS+=	R-ragg-[0-9]*:../../devel/R-ragg
TEST_DEPENDS+=	R-shiny-[0-9]*:../../www/R-shiny

USE_LANGUAGES+=	c c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
