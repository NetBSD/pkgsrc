# $NetBSD: Makefile,v 1.3 2019/07/31 20:16:40 brook Exp $

CATEGORIES=	math R

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/csgillespie/poweRlaw
COMMENT=	Analysis of heavy tailed distributions
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

R_PKGNAME=	poweRlaw
R_PKGVER=	0.70.2

DEPENDS+=	R-VGAM>=1.1.1:../../math/R-VGAM

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
