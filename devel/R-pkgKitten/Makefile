# $NetBSD: Makefile,v 1.2 2021/06/01 13:19:41 mef Exp $

R_PKGNAME=	pkgKitten
R_PKGVER=	0.2.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Create Simple Packages Which Do not Upset R Package Checks
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

# Package suggested but not available: 'whoami'

TEST_DEPENDS+=	R-tinytest-[0-9]*:../../devel/R-tinytest
TEST_DEPENDS+=	R-roxygen2-[0-9]*:../../devel/R-roxygen2

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
