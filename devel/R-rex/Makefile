# $NetBSD: Makefile,v 1.1 2019/10/13 11:47:21 rillig Exp $

R_PKGNAME=	rex
R_PKGVER=	1.1.2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Friendly Regular Expressions
LICENSE=	mit	# + file LICENSE

DEPENDS+=	R-lazyeval>=0.2.2:../../devel/R-lazyeval
DEPENDS+=	R-magrittr>=1.5:../../devel/R-magrittr

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
