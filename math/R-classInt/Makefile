# $NetBSD: Makefile,v 1.1.1.1 2009/12/11 19:11:00 adam Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/genetics/
COMMENT=	Package for choosing univariate class intervals for graphics

R_PKGNAME=	classInt
R_PKGVER=	0.1-13

USE_LANGUAGES=	fortran

DEPENDS+=	R-e1071>=1.5:../../math/R-e1071

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
