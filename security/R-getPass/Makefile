# $NetBSD: Makefile,v 1.2 2021/02/08 11:44:53 mef Exp $

R_PKGNAME=	getPass
R_PKGVER=	0.2-2
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Masked User Input
LICENSE=	2-clause-bsd  # and See LICENSE

DEPENDS+=	R-rstudioapi>=0.5:../../math/R-rstudioapi

TEST_DEPENDS+=	R-argon2-[0-9]*:../../security/R-argon2
TEST_DEPENDS+=	tex-parskip-[0-9]*:../../print/tex-parskip
TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-listings-[0-9]*:../../print/tex-listings
TEST_DEPENDS+=	tex-xcolor-[0-9]*:../../print/tex-xcolor

# make test fails as:
# Package suggested but not available: 'argon2'

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
