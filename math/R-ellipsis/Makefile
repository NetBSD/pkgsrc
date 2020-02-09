# $NetBSD: Makefile,v 1.4 2020/02/09 11:53:47 mef Exp $

R_PKGNAME=	ellipsis
R_PKGVER=	0.3.0
CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Tools for working with ...
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-rlang>=0.3.0:../../devel/R-rlang
TEST_DEPENDS+=	R-covr>=0:../../devel/R-covr
TEST_DEPENDS+=	R-testthat>=0:../../devel/R-testthat

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
