# $NetBSD: Makefile,v 1.2 2012/11/30 08:34:39 wen Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/xts/
COMMENT=	eXtensible Time Series
LICENSE=	gnu-gpl-v2

R_PKGNAME=	xts
R_PKGVER=	0.8-8

USE_LANGUAGES+=	c fortran

DEPENDS+=	R-zoo>=1.7.7:../../math/R-zoo

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
