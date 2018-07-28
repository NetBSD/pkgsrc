# $NetBSD: Makefile,v 1.11 2018/07/28 14:40:49 brook Exp $

CATEGORIES=	math

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
