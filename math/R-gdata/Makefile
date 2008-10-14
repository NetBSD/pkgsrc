# $NetBSD: Makefile,v 1.3 2008/10/14 07:31:26 markd Exp $
#

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/gdata/
COMMENT=	Various R programming tools for data manipulation

R_PKGNAME=	gdata
R_PKGVER=	2.4.2

DEPENDS+=	R-gtools>=2.2.3:../../math/R-gtools

REPLACE_PERL+=	inst/bin/*.bat inst/perl/*.pl
USE_TOOLS+=	perl:run

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
