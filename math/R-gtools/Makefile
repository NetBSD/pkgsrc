# $NetBSD: Makefile,v 1.4 2009/12/11 19:32:08 adam Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/gtools/
COMMENT=	Various R programming tools

R_PKGNAME=	gtools
R_PKGVER=	2.6.1

CHECK_WRKREF_SKIP+=	lib/R/library/gtools/libs/gtools.so

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
