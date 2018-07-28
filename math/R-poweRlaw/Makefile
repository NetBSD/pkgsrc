# $NetBSD: Makefile,v 1.2 2018/07/28 14:40:50 brook Exp $

CATEGORIES=	math

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/csgillespie/poweRlaw
COMMENT=	Analysis of heavy tailed distributions
LICENSE=	gnu-gpl-v2

DEPENDS+=	R-VGAM-[0-9]*:../../math/R-VGAM

R_PKGNAME=	poweRlaw
R_PKGVER=	0.70.1

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
