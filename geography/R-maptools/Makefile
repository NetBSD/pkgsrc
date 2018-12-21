# $NetBSD: Makefile,v 1.1 2018/12/21 12:08:04 wen Exp $

CATEGORIES=	geography

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/maptools/
COMMENT=	Tools for reading and handling spatial objects
LICENSE=	gnu-gpl-v2

R_PKGNAME=	maptools
R_PKGVER=	0.9-4

DEPENDS+=	R-sp>=1.0.11:../../math/R-sp

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
