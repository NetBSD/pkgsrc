# $NetBSD: Makefile,v 1.1 2021/01/01 05:09:26 mef Exp $

R_PKGNAME=	cpp11
R_PKGVER=	0.2.4
CATEGORIES=	lang

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	C++11 Interface for R's C Interface
LICENSE=	mit	# + file LICENSE

# Packages suggested but not available: 'bench', 'decor', 'lobstr'
TEST_DEPENDS+=	R-progress-[0-9]*:../../sysutils/R-progress

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
