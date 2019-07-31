# $NetBSD: Makefile,v 1.3 2019/07/31 19:52:48 brook Exp $

CATEGORIES=	math R

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/lmtest/
COMMENT=	Testing linear regression models
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

R_PKGNAME=	lmtest
R_PKGVER=	0.9-37

DEPENDS+=	R-zoo>=1.8.3:../../math/R-zoo
DEPENDS+=	R-zoo>=1.8.6:../../math/R-zoo

USE_LANGUAGES=	c fortran

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
