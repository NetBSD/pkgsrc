# $NetBSD: Makefile,v 1.12 2024/01/20 06:21:37 mef Exp $

R_PKGNAME=	evaluate
R_PKGVER=	0.23
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
