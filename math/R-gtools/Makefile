# $NetBSD: Makefile,v 1.8 2019/07/31 19:41:56 brook Exp $

CATEGORIES=	math R

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/gtools/
COMMENT=	Various R programming tools
LICENSE=	gnu-gpl-v2

R_PKGNAME=	gtools
R_PKGVER=	3.8.1

USE_LANGUAGES=	c

CHECK_WRKREF_SKIP+=	lib/R/library/gtools/libs/gtools.so

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
