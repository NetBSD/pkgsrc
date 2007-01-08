# $NetBSD: Makefile,v 1.2 2007/01/08 04:40:27 rillig Exp $
#

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/gtools.html
COMMENT=	Various R programming tools

R_PKGNAME=	gtools
R_PKGVER=	2.2.3

CHECK_WRKREF_SKIP+=	lib/R/library/gtools/libs/gtools.so

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
