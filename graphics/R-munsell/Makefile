# $NetBSD: Makefile,v 1.2 2018/07/28 14:40:44 brook Exp $

CATEGORIES=	graphics

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/munsell/
COMMENT=	Utilities for using Munsell colors
LICENSE=	mit

R_PKGNAME=	munsell
R_PKGVER=	0.4.3

DEPENDS+=	R-colorspace-[0-9]*:../../graphics/R-colorspace

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
