# $NetBSD: Makefile,v 1.2 2021/06/05 04:28:38 mef Exp $

R_PKGNAME=	brio
R_PKGVER=	1.1.2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Basic R Input Output
LICENSE=	mit	# + file LICENSE

TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
