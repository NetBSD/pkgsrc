# $NetBSD: Makefile,v 1.1.1.1 2012/04/15 17:33:04 brook Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/spacetime/
COMMENT=	Classes and methods for spatio-temporal data
LICENSE=	gnu-gpl-v2

R_PKGNAME=	spacetime
R_PKGVER=	0.6-2

DEPENDS+=	R-sp>=0.9.98:../../math/R-sp
DEPENDS+=	R-xts>=0.8.6:../../math/R-xts
DEPENDS+=	R-zoo>=1.7.7:../../math/R-zoo

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
