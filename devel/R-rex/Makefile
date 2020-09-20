# $NetBSD: Makefile,v 1.2 2020/09/20 21:44:21 mef Exp $

R_PKGNAME=	rex
R_PKGVER=	1.2.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Friendly Regular Expressions
LICENSE=	mit	# + file LICENSE

DEPENDS+=	R-lazyeval>=0.2.2:../../devel/R-lazyeval
DEPENDS+=	R-magrittr>=1.5:../../devel/R-magrittr

TEST_DEPENDS+=	R-Hmisc-[0-9]*:../../misc/R-Hmisc
TEST_DEPENDS+=	R-rvest-[0-9]*:../../www/R-rvest


USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
