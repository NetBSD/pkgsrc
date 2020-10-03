# $NetBSD: Makefile,v 1.5 2020/10/03 13:45:51 mef Exp $

R_PKGNAME=	ellipsis
R_PKGVER=	0.3.1
#ATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Collection of functions to catch problems and alert the user
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-rlang>=0.3.0:../../devel/R-rlang
TEST_DEPENDS+=	R-covr>=0:../../devel/R-covr
TEST_DEPENDS+=	R-testthat>=0:../../devel/R-testthat

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
