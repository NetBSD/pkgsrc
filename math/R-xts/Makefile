# $NetBSD: Makefile,v 1.12 2019/08/08 19:53:55 brook Exp $

R_PKGNAME=	xts
R_PKGVER=	0.11-2
CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	eXtensible Time Series
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-zoo>=1.7.12:../../math/R-zoo

USE_LANGUAGES+=	c fortran

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
