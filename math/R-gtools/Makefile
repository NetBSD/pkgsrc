# $NetBSD: Makefile,v 1.9 2019/08/08 19:53:50 brook Exp $

R_PKGNAME=	gtools
R_PKGVER=	3.8.1
CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Various R programming tools
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c

CHECK_WRKREF_SKIP+=	lib/R/library/gtools/libs/gtools.so

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
