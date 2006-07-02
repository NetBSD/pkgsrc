# $NetBSD: Makefile,v 1.1.1.1 2006/07/02 13:04:13 markd Exp $
#

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/gdata.html
COMMENT=	Various R programming tools for data manipulation

R_PKGNAME=	gdata
R_PKGVER=	2.1.2

DEPENDS+=	R-gtools>=2.2.3:../../math/R-gtools

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
