# $NetBSD: Makefile,v 1.9 2019/07/31 19:09:38 brook Exp $

CATEGORIES=	math R

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/genetics/
COMMENT=	Choose univariate class intervals
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

R_PKGNAME=	classInt
R_PKGVER=	0.3-3

DEPENDS+=	R-e1071>=1.6.8:../../math/R-e1071

USE_LANGUAGES=	c fortran

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
