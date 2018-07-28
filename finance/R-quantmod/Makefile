# $NetBSD: Makefile,v 1.2 2018/07/28 14:40:44 brook Exp $

CATEGORIES=	finance

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.quantmod.com/
COMMENT=	Quantitative financial modeling framework
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-TTR>=0.2:../../finance/R-TTR
DEPENDS+=	R-xts>=0.9.0:../../math/R-xts
DEPENDS+=	R-zoo-[0-9]*:../../math/R-zoo

R_PKGNAME=	quantmod
R_PKGVER=	0.4-12

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
