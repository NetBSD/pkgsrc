# $NetBSD: Makefile,v 1.26 2025/02/15 04:40:08 mef Exp $

R_PKGNAME=	mvtnorm
R_PKGVER=	1.3-3

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Multivariate normal and t distributions
LICENSE=	gnu-gpl-v2

# Package suggested but not available: 'qrng'
TEST_DEPENDS+=	R-numDeriv-[0-9]*:../../math/R-numDeriv

USE_LANGUAGES=	c fortran

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
