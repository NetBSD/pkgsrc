# $NetBSD: Makefile,v 1.14 2021/06/15 14:25:14 jperkin Exp $

R_PKGNAME=	classInt
R_PKGVER=	0.4-3

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Choose univariate class intervals
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-e1071>=1.7.2:../../math/R-e1071

TEST_DEPENDS+=	R-spData-[0-9]*:../../geography/R-spData
TEST_DEPENDS+=	R-units-[0-9]*:../../math/R-units

USE_LANGUAGES=	c fortran

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
