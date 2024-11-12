# $NetBSD: Makefile,v 1.25 2024/11/12 14:35:29 mef Exp $

R_PKGNAME=	mvtnorm
R_PKGVER=	1.3-2

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Multivariate normal and t distributions
LICENSE=	gnu-gpl-v2

# Package suggested but not available: 'qrng'
TEST_DEPENDS+=	R-numDeriv-[0-9]*:../../math/R-numDeriv

USE_LANGUAGES=	c fortran

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
