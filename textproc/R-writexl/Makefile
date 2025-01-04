# $NetBSD: Makefile,v 1.2 2025/01/04 00:59:53 mef Exp $

R_PKGNAME=	writexl
R_PKGVER=	1.5.1
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Export Data Frames to Excel 'xlsx' Format
LICENSE=	2-clause-bsd	# + file LICENSE

# Package suggested but not available: 'nycflights13'
TEST_DEPENDS+=	R-bit64-[0-9]*:../../devel/R-bit64
TEST_DEPENDS+=	R-readxl-[0-9]*:../../textproc/R-readxl
TEST_DEPENDS+=	R-spelling-[0-9]*:../../textproc/R-spelling
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
