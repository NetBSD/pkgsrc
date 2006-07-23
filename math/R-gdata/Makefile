# $NetBSD: Makefile,v 1.2 2006/07/23 16:59:22 rillig Exp $
#

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/gdata.html
COMMENT=	Various R programming tools for data manipulation

R_PKGNAME=	gdata
R_PKGVER=	2.1.2
PKGREVISION=	1

DEPENDS+=	R-gtools>=2.2.3:../../math/R-gtools

REPLACE_PERL+=	inst/bin/*.bat inst/perl/*.pl
USE_TOOLS+=	perl:run

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
