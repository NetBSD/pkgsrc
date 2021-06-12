# $NetBSD: Makefile,v 1.4 2021/06/12 01:43:34 mef Exp $

R_PKGNAME=	remotes
R_PKGVER=	2.4.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	R package installation from remote repositories, including 'GitHub'
LICENSE=	mit

# Package suggested but not available: 'webfakes'
#EST_DEPENDS+=	R-webfake-[0-9]*:../../www/R-webfakes
TEST_DEPENDS+=	R-mockery-[0-9]*:../../devel/R-mockery

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
