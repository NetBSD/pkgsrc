# $NetBSD: Makefile,v 1.4 2019/08/08 19:53:41 brook Exp $

R_PKGNAME=	quantmod
R_PKGVER=	0.4-15
CATEGORIES=	finance

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Quantitative financial modelling framework
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-TTR>=0.2:../../finance/R-TTR
DEPENDS+=	R-xts>=0.9.0:../../math/R-xts
DEPENDS+=	R-zoo>=1.8.6:../../math/R-zoo
DEPENDS+=	R-curl>=4.0:../../www/R-curl

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../math/R-xts/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
