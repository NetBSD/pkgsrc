# $NetBSD: Makefile,v 1.6 2011/09/26 19:36:54 ryoon Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	mchittur@cs.nmsu.edu
HOMEPAGE=	${R_HOMEPAGE_BASE}/Rcmdr/
COMMENT=	Platform-independent basic-statistics GUI for R

R_PKGNAME=	Rcmdr
R_PKGVER=	1.5-3

DEPENDS+=	R-car>=2.0:../../math/R-car

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
