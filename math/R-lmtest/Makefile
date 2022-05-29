# $NetBSD: Makefile,v 1.5 2022/05/29 09:48:05 wen Exp $

R_PKGNAME=	lmtest
R_PKGVER=	0.9-40
CATEGORIES=	math

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Testing linear regression models
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-zoo>=1.8.6:../../math/R-zoo

USE_LANGUAGES=	c fortran

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
