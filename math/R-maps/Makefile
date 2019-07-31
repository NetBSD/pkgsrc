# $NetBSD: Makefile,v 1.12 2019/07/31 19:55:15 brook Exp $

CATEGORIES=	math R

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/maps/
COMMENT=	Draw geographical maps
LICENSE=	gnu-gpl-v2

R_PKGNAME=	maps
R_PKGVER=	3.3.0

USE_TOOLS+=	gmake
MAKE_ENV+=	AWK=${AWK:Q}
USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
