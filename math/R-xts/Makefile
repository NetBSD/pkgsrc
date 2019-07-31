# $NetBSD: Makefile,v 1.11 2019/07/31 20:39:14 brook Exp $

CATEGORIES=	math R

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/xts/
COMMENT=	eXtensible Time Series
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

R_PKGNAME=	xts
R_PKGVER=	0.11-2

DEPENDS+=	R-zoo>=1.7.12:../../math/R-zoo

USE_LANGUAGES+=	c fortran

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
