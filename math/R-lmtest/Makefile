# $NetBSD: Makefile,v 1.4 2019/08/08 19:53:51 brook Exp $

R_PKGNAME=	lmtest
R_PKGVER=	0.9-37
CATEGORIES=	math

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Testing linear regression models
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-zoo>=1.8.3:../../math/R-zoo
DEPENDS+=	R-zoo>=1.8.6:../../math/R-zoo

USE_LANGUAGES=	c fortran

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
