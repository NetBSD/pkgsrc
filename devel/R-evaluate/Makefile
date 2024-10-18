# $NetBSD: Makefile,v 1.13 2024/10/18 12:22:13 mef Exp $

R_PKGNAME=	evaluate
R_PKGVER=	1.0.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Parsing and evaluation tools
LICENSE=	mit

DEPENDS+=	R-stringr>=0.6.2:../../textproc/R-stringr

TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-ggplot2-[0-9]*:../../graphics/R-ggplot2
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
