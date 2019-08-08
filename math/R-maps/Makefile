# $NetBSD: Makefile,v 1.13 2019/08/08 19:53:51 brook Exp $

R_PKGNAME=	maps
R_PKGVER=	3.3.0
CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Draw geographical maps
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake
MAKE_ENV+=	AWK=${AWK:Q}
USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
