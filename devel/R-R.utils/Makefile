# $NetBSD: Makefile,v 1.5 2022/12/17 23:48:27 mef Exp $

R_PKGNAME=	R.utils
R_PKGVER=	2.12.2
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
