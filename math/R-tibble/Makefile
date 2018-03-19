# $NetBSD: Makefile,v 1.1 2018/03/19 15:27:45 minskim Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

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
