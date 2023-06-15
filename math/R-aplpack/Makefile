# $NetBSD: Makefile,v 1.5 2023/06/15 10:52:04 mef Exp $

R_PKGNAME=	aplpack
R_PKGVER=	1.3.5
CATEGORIES=	math

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Functions for drawing special plots
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

TEST_DEPENDS+=	R-jpeg-[0-9]*:../../graphics/R-jpeg
TEST_DEPENDS+=	R-png-[0-9]*:../../graphics/R-png
TEST_DEPENDS+=	R-tkrplot-[0-9]*:../../graphics/R-tkrplot

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
