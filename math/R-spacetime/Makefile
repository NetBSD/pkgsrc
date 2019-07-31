# $NetBSD: Makefile,v 1.6 2019/07/31 20:30:02 brook Exp $

CATEGORIES=	math R

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/spacetime/
COMMENT=	Classes and methods for spatio-temporal data
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

R_PKGNAME=	spacetime
R_PKGVER=	1.2-2

DEPENDS+=	R-intervals>=0.15.1:../../math/R-intervals
DEPENDS+=	R-sp>=1.1.0:../../math/R-sp
DEPENDS+=	R-xts>=0.8.8:../../math/R-xts
DEPENDS+=	R-zoo>=1.7.9:../../math/R-zoo

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../math/R-xts/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
