# $NetBSD: Makefile,v 1.7 2018/07/28 14:40:48 brook Exp $

CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/gtools/
COMMENT=	Various R programming tools
LICENSE=	gnu-lgpl-v2.1

R_PKGNAME=	gtools
R_PKGVER=	3.5.0

CHECK_WRKREF_SKIP+=	lib/R/library/gtools/libs/gtools.so

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
