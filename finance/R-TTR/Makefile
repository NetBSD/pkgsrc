# $NetBSD: Makefile,v 1.5 2022/05/29 00:46:45 wen Exp $

R_PKGNAME=	TTR
R_PKGVER=	0.24.3
CATEGORIES=	finance

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Technical trading rules
LICENSE=	gnu-gpl-v2

DEPENDS+=	R-zoo>=1.8.6:../../math/R-zoo
DEPENDS+=	R-curl>=4.0:../../www/R-curl

USE_LANGUAGES=	c fortran

.include "../../math/R/Makefile.extension"
.include "../../math/R-xts/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
