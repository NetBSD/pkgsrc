# $NetBSD: Makefile,v 1.10 2018/08/30 12:27:57 wen Exp $

CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/xts/
COMMENT=	R's eXtensible Time Series
LICENSE=	gnu-gpl-v2

R_PKGNAME=	xts
R_PKGVER=	0.11-0

USE_LANGUAGES+=	c fortran

DEPENDS+=	R-zoo>=1.7.12:../../math/R-zoo

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
