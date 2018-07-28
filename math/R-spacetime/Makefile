# $NetBSD: Makefile,v 1.5 2018/07/28 14:40:51 brook Exp $

CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/spacetime/
COMMENT=	Classes and methods for spatio-temporal data
LICENSE=	gnu-gpl-v2

R_PKGNAME=	spacetime
R_PKGVER=	1.1-4

DEPENDS+=	R-sp>=1.1.0:../../math/R-sp
DEPENDS+=	R-xts>=0.8.8:../../math/R-xts
DEPENDS+=	R-zoo>=1.7.9:../../math/R-zoo
DEPENDS+=	R-intervals>=0:../../math/R-intervals

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
