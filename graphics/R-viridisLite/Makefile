# $NetBSD: Makefile,v 1.2 2018/07/28 14:40:45 brook Exp $

CATEGORIES=	graphics

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
