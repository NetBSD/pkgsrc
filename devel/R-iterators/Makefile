# $NetBSD: Makefile,v 1.6 2022/12/18 02:17:25 mef Exp $

R_PKGNAME=	iterators
R_PKGVER=	1.0.14
CATEGORIES=	devel

MAINTAINER=	mishka@NetBSD.org
COMMENT=	Provides iterator construct
LICENSE=	apache-2.0

TEST_DEPENDS+=	R-RUnit-[0-9]*:../../devel/R-RUnit
TEST_DEPENDS+=	R-foreach-[0-9]*:../../devel/R-foreach

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
