# $NetBSD: Makefile,v 1.2 2021/09/08 00:27:17 mef Exp $

R_PKGNAME=	R.utils
R_PKGVER=	2.10.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Various Programming Utilities
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	R-R.methodsS3-[0-9]*:../../devel/R-R.methodsS3
DEPENDS+=	R-R.oo-[0-9]*:../../devel/R-R.oo

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
