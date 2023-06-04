# $NetBSD: Makefile,v 1.7 2023/06/04 03:04:44 mef Exp $

R_PKGNAME=	FNN
R_PKGVER=	1.1.3.2

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Fast nearest neighbor search algorithms and applications
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

# Packages suggested but not available: 'chemometrics'
TEST_DEPENDS+=	R-mvtnorm-[0-9]*:../../math/R-mvtnorm

USE_LANGUAGES+=	c c++

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
