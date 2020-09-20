# $NetBSD: Makefile,v 1.6 2020/09/20 09:55:09 mef Exp $

R_PKGNAME=	jsonlite
R_PKGVER=	1.7.1
CATEGORIES=	textproc

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Robust, high performance JSON parser and generator for R
LICENSE=	mit

TEST_DEPENDS+=	R-sf-[0-9]*:../../geography/R-sf

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
