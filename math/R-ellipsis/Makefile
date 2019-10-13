# $NetBSD: Makefile,v 1.3 2019/10/13 12:22:27 rillig Exp $

R_PKGNAME=	ellipsis
R_PKGVER=	0.2.0.1
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
