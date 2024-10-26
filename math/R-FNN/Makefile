# $NetBSD: Makefile,v 1.9 2024/10/26 06:23:38 mef Exp $

R_PKGNAME=	FNN
R_PKGVER=	1.1.4.1

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Fast nearest neighbor search algorithms and applications
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

# Packages suggested but not available: 'chemometrics'
TEST_DEPENDS+=	R-mvtnorm-[0-9]*:../../math/R-mvtnorm

USE_LANGUAGES+=	c c++

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
