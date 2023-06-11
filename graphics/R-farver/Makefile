# $NetBSD: Makefile,v 1.3 2023/06/11 10:57:10 mef Exp $

R_PKGNAME=	farver
R_PKGVER=	2.1.1
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	High Performance Colour Space Manipulation
LICENSE=	mit

TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat

USE_LANGUAGES=	c++

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
