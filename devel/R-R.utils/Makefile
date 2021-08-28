# $NetBSD: Makefile,v 1.1 2021/08/28 04:47:17 mef Exp $

R_PKGNAME=	R.utils
R_PKGVER=	2.10.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Various Programming Utilities
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	R-R.methodsS3-[0-9]*:../../devel/R-R.methodsS3

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
