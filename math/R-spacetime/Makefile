# $NetBSD: Makefile,v 1.2 2013/01/24 01:40:57 wen Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/spacetime/
COMMENT=	Classes and methods for spatio-temporal data
LICENSE=	gnu-gpl-v2

R_PKGNAME=	spacetime
R_PKGVER=	1.0-3

DEPENDS+=	R-sp>=0.9.98:../../math/R-sp
DEPENDS+=	R-xts>=0.8.8:../../math/R-xts
DEPENDS+=	R-zoo>=1.7.9:../../math/R-zoo
DEPENDS+=	R-intervals>=0:../../math/R-intervals

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
