# $NetBSD: Makefile,v 1.2 2024/02/06 13:36:24 mef Exp $

R_PKGNAME=	pracma
R_PKGVER=	2.4.4

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Practical Numerical Math Functions
LICENSE=	gnu-gpl-v3

# Package suggested but not available: 'NlcOptim'

TEST_DEPENDS+=	R-quadprog-[0-9]*:../../math/R-quadprog

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
