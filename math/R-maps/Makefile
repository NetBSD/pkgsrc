# $NetBSD: Makefile,v 1.10 2016/09/29 12:10:50 joerg Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/maps/
COMMENT=	Display maps in R
LICENSE=	gnu-gpl-v2

R_PKGNAME=	maps
R_PKGVER=	2.3-9

USE_TOOLS+=	gmake
MAKE_ENV+=	AWK=${AWK:Q}

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
