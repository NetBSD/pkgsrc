# $NetBSD: Makefile,v 1.1 2020/01/13 01:51:57 mef Exp $

R_PKGNAME=	prettycode
R_PKGVER=	1.1.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Pretty Print R Code in the Terminal
LICENSE=	mit	# + file LICENSE

DEPENDS+=	R-crayon>=1.3.4:../../devel/R-crayon

#TEST_DEPENDS+=	R-mockery-[0-9]*:../../

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
