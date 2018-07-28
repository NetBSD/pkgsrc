# $NetBSD: Makefile,v 1.2 2018/07/28 14:40:43 brook Exp $

CATEGORIES=	finance

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/joshuaulrich/TTR
COMMENT=	Technical trading rules
LICENSE=	gnu-gpl-v2

DEPENDS+=	R-curl-[0-9]*:../../www/R-curl
DEPENDS+=	R-zoo-[0-9]*:../../math/R-zoo

R_PKGNAME=	TTR
R_PKGVER=	0.23-3

USE_LANGUAGES=	c fortran

.include "../../math/R-xts/buildlink3.mk"
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
