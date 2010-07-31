# $NetBSD: Makefile,v 1.7 2010/07/31 22:19:16 dholland Exp $

CATEGORIES=	databases math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	mchittur@cs.nmsu.edu
HOMEPAGE=	${R_HOMEPAGE_BASE}/DAAG/
COMMENT=	Example data sets and functions implemented in R

R_PKGNAME=	DAAG
R_PKGVER=	1.01

DEPENDS+=	R-randomForest>=4.5:../../math/R-randomForest

.include "../../math/R/Makefile.extension"
INSTALLATION_DIRS+=	lib/R/doc/html/search
.include "../../mk/bsd.pkg.mk"
