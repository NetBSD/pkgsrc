# $NetBSD: Makefile,v 1.7 2019/08/08 19:53:54 brook Exp $

R_PKGNAME=	spacetime
R_PKGVER=	1.2-2
CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Classes and methods for spatio-temporal data
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-intervals>=0.15.1:../../math/R-intervals
DEPENDS+=	R-sp>=1.1.0:../../math/R-sp
DEPENDS+=	R-xts>=0.8.8:../../math/R-xts
DEPENDS+=	R-zoo>=1.7.9:../../math/R-zoo

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../math/R-xts/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
