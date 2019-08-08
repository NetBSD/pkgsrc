# $NetBSD: Makefile,v 1.7 2019/08/08 19:53:47 brook Exp $

R_PKGNAME=	car
R_PKGVER=	3.0-3
CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Companion to 'Applied Regression'
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-rio>=0.5.16:../../devel/R-rio
DEPENDS+=	R-maptools>=0.9.5:../../geography/R-maptools
DEPENDS+=	R-abind>=1.4.5:../../math/R-abind
DEPENDS+=	R-carData>=3.0.0:../../math/R-carData
DEPENDS+=	R-lme4>=1.1.21:../../math/R-lme4
DEPENDS+=	R-pbkrtest>=0.4.4:../../math/R-pbkrtest
DEPENDS+=	R-quantreg>=5.42.1:../../math/R-quantreg

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
