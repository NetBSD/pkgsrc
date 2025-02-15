# $NetBSD: Makefile,v 1.8 2025/02/15 23:54:07 mef Exp $

R_PKGNAME=	R6
R_PKGVER=	2.6.1
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Encapsulated classes with reference semantics
LICENSE=	mit

# Package suggested but not available: 'lobstr'
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
