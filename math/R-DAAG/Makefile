# $NetBSD: Makefile,v 1.6 2009/12/21 11:51:19 adam Exp $

CATEGORIES=	databases math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	mchittur@cs.nmsu.edu
HOMEPAGE=	${R_HOMEPAGE_BASE}/DAAG/
COMMENT=	Example data sets and functions implmented in R

R_PKGNAME=	DAAG
R_PKGVER=	1.01

DEPENDS+=	R-randomForest>=4.5:../../math/R-randomForest

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
