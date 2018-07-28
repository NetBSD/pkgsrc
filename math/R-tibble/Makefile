# $NetBSD: Makefile,v 1.2 2018/07/28 14:40:51 brook Exp $

CATEGORIES=	math

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://tibble.tidyverse.org/
COMMENT=	Simple data frames
LICENSE=	mit

R_PKGNAME=	tibble
R_PKGVER=	1.4.2

DEPENDS+=	R-cli-[0-9]*:../../devel/R-cli
DEPENDS+=	R-crayon-[0-9]*:../../devel/R-crayon
DEPENDS+=	R-pillar>=1.1.0:../../misc/R-pillar
DEPENDS+=	R-rlang-[0-9]*:../../devel/R-rlang

USE_LANGUAGES=	c

BUILDLINK_API_DEPENDS.R+=	R>=3.1.0
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
