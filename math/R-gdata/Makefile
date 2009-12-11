# $NetBSD: Makefile,v 1.4 2009/12/11 19:28:43 adam Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/gdata/
COMMENT=	Various R programming tools for data manipulation

R_PKGNAME=	gdata
R_PKGVER=	2.6.1

DEPENDS+=	R-gtools>=2.6.1:../../math/R-gtools

USE_TOOLS+=	perl:run
REPLACE_PERL+=	inst/bin/*.bat inst/perl/*.pl

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
