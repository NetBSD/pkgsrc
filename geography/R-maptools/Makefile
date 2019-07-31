# $NetBSD: Makefile,v 1.2 2019/07/31 15:58:35 brook Exp $

CATEGORIES=	geography R

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/maptools/
COMMENT=	Tools for handling spatial objects
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

R_PKGNAME=	maptools
R_PKGVER=	0.9-5

DEPENDS+=	R-sp>=1.0.11:../../math/R-sp

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
