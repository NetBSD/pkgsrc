# $NetBSD: Makefile,v 1.1 2018/03/03 01:23:29 minskim Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

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
