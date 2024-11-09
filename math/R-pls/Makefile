# $NetBSD: Makefile,v 1.2 2024/11/09 22:31:33 mef Exp $

R_PKGNAME=	pls
R_PKGVER=	2.8-5

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Partial Least Squares and Principal Component Regression
LICENSE=	gnu-gpl-v2

# Package suggested but not available: 'Rmpi'
#  Rmpi may need OPENMPI package (mpi.h)
TEST_DEPENDS+=	R-RUnit-[0-9]*:../../devel/R-RUnit
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
