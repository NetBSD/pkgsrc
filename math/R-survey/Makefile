# $NetBSD: Makefile,v 1.1 2019/07/31 13:30:20 brook Exp $

CATEGORIES=	math R

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/survey/
COMMENT=	Analysis of complex survey samples
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

R_PKGNAME=	survey
R_PKGVER=	3.36

DEPENDS+=	R-minqa>=1.2.4:../../math/R-minqa
DEPENDS+=	R-mitools>=2.4:../../math/R-mitools
DEPENDS+=	R-numDeriv>=2016.8.1.1:../../math/R-numDeriv

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
