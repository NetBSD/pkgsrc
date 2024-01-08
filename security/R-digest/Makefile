# $NetBSD: Makefile,v 1.11 2024/01/08 07:31:50 mef Exp $

R_PKGNAME=	digest
R_PKGVER=	0.6.33
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Create compact hash digests of R objects
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

USE_LANGUAGES+=	c c++

# Packages suggested but not available: 'simplermarkdown'
TEST_DEPENDS+=	R-tinytst-[0-9]*:../../devel/R-tinytest

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
