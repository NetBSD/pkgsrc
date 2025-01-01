# $NetBSD: Makefile,v 1.2 2025/01/01 22:29:10 mef Exp $

R_PKGNAME=	Rdpack
R_PKGVER=	2.6.2
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Update and Manipulate Rd Documentation Objects
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-rbibutils-[0-9]*:../../textproc/R-rbibutils

# Package suggested but not available: 'gbRd'
TEST_DEPENDS+=	R-rprojroot-[0-9]*:../../devel/R-rprojroot
TEST_DEPENDS+=	R-rstudioapi-[0-9]*:../../math/R-rstudioapi
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat


USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
