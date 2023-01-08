# $NetBSD: Makefile,v 1.5 2023/01/08 03:39:59 wen Exp $

R_PKGNAME=	tseries
R_PKGVER=	0.10-52
CATEGORIES=	finance

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Time series analysis and computational finance
LICENSE=	gnu-gpl-v2

DEPENDS+=	R-quantmod>=0.4.9:../../finance/R-quantmod
DEPENDS+=	R-quadprog>=1.5.7:../../math/R-quadprog
DEPENDS+=	R-zoo>=1.8.6:../../math/R-zoo

USE_LANGUAGES=	c fortran

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
