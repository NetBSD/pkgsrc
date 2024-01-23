# $NetBSD: Makefile,v 1.8 2024/01/23 22:13:44 mef Exp $

R_PKGNAME=	FNN
R_PKGVER=	1.1.4

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Fast nearest neighbor search algorithms and applications
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

# Packages suggested but not available: 'chemometrics'
TEST_DEPENDS+=	R-mvtnorm-[0-9]*:../../math/R-mvtnorm

USE_LANGUAGES+=	c c++

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
