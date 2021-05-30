# $NetBSD: Makefile,v 1.1 2021/05/30 02:36:31 mef Exp $

R_PKGNAME=	disposables
R_PKGVER=	1.0.3
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Create Disposable R Packages for Testing
LICENSE=	mit	# + file LICENSE

TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
