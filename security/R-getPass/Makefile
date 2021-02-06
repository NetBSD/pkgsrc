# $NetBSD: Makefile,v 1.1 2021/02/06 23:07:00 mef Exp $

R_PKGNAME=	getPass
R_PKGVER=	0.2-2
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Masked User Input
LICENSE=	2-clause-bsd  # and See LICENSE

DEPENDS+=	R-rstudioapi>=0.5:../../math/R-rstudioapi

# Package suggested but not available: 'argon2'
#TEST_DEPEDS+=	R-argon2-[0-9]:../../


# make test fails as:
# Package suggested but not available: 'argon2'

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
