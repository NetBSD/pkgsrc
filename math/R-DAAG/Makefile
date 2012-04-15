# $NetBSD: Makefile,v 1.9 2012/04/15 13:33:06 brook Exp $

CATEGORIES=	databases math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/DAAG/
COMMENT=	Example data sets and functions implemented in R
# LICENSE=	Unlimited

R_PKGNAME=	DAAG
R_PKGVER=	1.12

DEPENDS+=	R-randomForest>=4.6.6:../../math/R-randomForest

INSTALLATION_DIRS+=	lib/R/doc/html/search

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
