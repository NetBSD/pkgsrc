# $NetBSD: Makefile,v 1.2 2021/08/31 21:45:35 mef Exp $

R_PKGNAME=	R.oo
R_PKGVER=	1.24.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	R Object-Oriented Programming with or without References
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	R-R.methodsS3-[0-9]*:../../devel/R-R.methodsS3

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
