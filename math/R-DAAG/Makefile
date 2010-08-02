# $NetBSD: Makefile,v 1.8 2010/08/02 09:01:01 dholland Exp $

CATEGORIES=	databases math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	mchittur@cs.nmsu.edu
HOMEPAGE=	${R_HOMEPAGE_BASE}/DAAG/
COMMENT=	Example data sets and functions implemented in R

R_PKGNAME=	DAAG
R_PKGVER=	1.01
PKGREVISION=	1

DEPENDS+=	R-randomForest>=4.5:../../math/R-randomForest

.include "../../math/R/Makefile.extension"
INSTALLATION_DIRS+=	lib/R/doc/html/search
.include "../../mk/bsd.pkg.mk"
