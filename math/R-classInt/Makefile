# $NetBSD: Makefile,v 1.4 2011/11/20 05:00:51 markd Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/genetics/
COMMENT=	Package for choosing univariate class intervals for graphics

R_PKGNAME=	classInt
R_PKGVER=	0.1-14

USE_LANGUAGES=	c fortran77

DEPENDS+=	R-e1071>=1.5:../../math/R-e1071

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
