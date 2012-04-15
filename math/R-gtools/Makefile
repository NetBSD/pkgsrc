# $NetBSD: Makefile,v 1.5 2012/04/15 15:26:35 brook Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/gtools/
COMMENT=	Various R programming tools
LICENSE=	gnu-lgpl-v2.1

R_PKGNAME=	gtools
R_PKGVER=	2.6.2

CHECK_WRKREF_SKIP+=	lib/R/library/gtools/libs/gtools.so

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
