# $NetBSD: Makefile,v 1.3 2019/07/31 15:46:40 brook Exp $

CATEGORIES=	finance R

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/joshuaulrich/TTR
COMMENT=	Technical trading rules
LICENSE=	gnu-gpl-v2

R_PKGNAME=	TTR
R_PKGVER=	0.23-4

DEPENDS+=	R-zoo>=1.8.6:../../math/R-zoo
DEPENDS+=	R-curl>=4.0:../../www/R-curl

USE_LANGUAGES=	c fortran

.include "../../math/R/Makefile.extension"
.include "../../math/R-xts/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
