# $NetBSD: Makefile,v 1.1 2018/03/11 03:43:29 minskim Exp $

CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/sjmgarnier/viridisLite
COMMENT=	Default color maps from matplotlib
LICENSE=	mit

R_PKGNAME=	viridisLite
R_PKGVER=	0.3.0

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.R+=	R>=2.10
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
