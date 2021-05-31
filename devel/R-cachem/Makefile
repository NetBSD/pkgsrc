# $NetBSD: Makefile,v 1.1 2021/05/31 22:33:11 mef Exp $

R_PKGNAME=	cachem
R_PKGVER=	1.0.5
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Cache R Objects with Automatic Pruning
LICENSE=	mit	# + file LICENSE

DEPENDS+=	R-rlang>=0.4.10:../../devel/R-rlang
DEPENDS+=	R-fastmap-[0-9]*:../../devel/R-fastmap

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
