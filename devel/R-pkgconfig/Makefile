# $NetBSD: Makefile,v 1.6 2021/05/30 02:46:26 mef Exp $

R_PKGNAME=	pkgconfig
R_PKGVER=	2.0.3
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Private configuration for R packages
LICENSE=	mit

TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-disposables-[0-9]*:../../devel/R-disposables

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
