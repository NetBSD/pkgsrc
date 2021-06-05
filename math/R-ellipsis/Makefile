# $NetBSD: Makefile,v 1.7 2021/06/05 06:27:32 mef Exp $

R_PKGNAME=	ellipsis
R_PKGVER=	0.3.2
#ATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Collection of functions to catch problems and alert the user
LICENSE=	mit

DEPENDS+=	R-rlang>=0.3.0:../../devel/R-rlang
TEST_DEPENDS+=	R-covr>=0:../../devel/R-covr
TEST_DEPENDS+=	R-testthat>=0:../../devel/R-testthat

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
