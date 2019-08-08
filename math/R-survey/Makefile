# $NetBSD: Makefile,v 1.2 2019/08/08 19:53:54 brook Exp $

R_PKGNAME=	survey
R_PKGVER=	3.36
CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Analysis of complex survey samples
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-minqa>=1.2.4:../../math/R-minqa
DEPENDS+=	R-mitools>=2.4:../../math/R-mitools
DEPENDS+=	R-numDeriv>=2016.8.1.1:../../math/R-numDeriv

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
