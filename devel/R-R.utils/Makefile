# $NetBSD: Makefile,v 1.4 2021/11/28 01:03:28 mef Exp $

R_PKGNAME=	R.utils
R_PKGVER=	2.11.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Various Programming Utilities
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	R-R.methodsS3-[0-9]*:../../devel/R-R.methodsS3
DEPENDS+=	R-R.oo-[0-9]*:../../devel/R-R.oo

TEST_DEPENDS+=	R-R.oo-[0-9]*:../../devel/R-R.oo
TEST_DEPENDS+=	R-R.methodsS3-[0-9]*:../../devel/R-R.methodsS3

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
