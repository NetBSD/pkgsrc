# $NetBSD: Makefile,v 1.7 2026/07/13 14:09:26 mef Exp $

R_PKGNAME=	survey
R_PKGVER=	4.5

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Analysis of complex survey samples
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-minqa>=1.2.4:../../math/R-minqa
DEPENDS+=	R-mitools>=2.4:../../math/R-mitools
DEPENDS+=	R-numDeriv-[0-9]*:../../math/R-numDeriv

# Packages suggested but not available:
#   'CompQuadForm', 'AER', 'SUMMER', 'R.rsp'

TEST_DEPENDS+=	R-hexbin-[0-9]*:../../math/R-hexbin
TEST_DEPENDS+=	R-RSQLite-[0-9]*:../../databases/R-RSQLite
TEST_DEPENDS+=	R-quantreg-[0-9]*:../../math/R-quantreg

USE_LANGUAGES=	c++
GCC_REQD+=	8

.include "../../mk/bsd.prefs.mk"
pre-patch:
.if ${OPSYS} != SunOS && ${OPSYS} != Linux && ${OPSYS} != Darwin
	${CP} ${FILESDIR}/Makevars ${WRKSRC}/src/
.endif
.include "../../math/R-RcppArmadillo/buildlink3.mk"
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
