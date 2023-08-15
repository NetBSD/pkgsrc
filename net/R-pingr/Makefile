# $NetBSD: Makefile,v 1.4 2023/08/15 01:21:16 mef Exp $

R_PKGNAME=	pingr
R_PKGVER=	2.0.2
CATEGORIES=	net

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Check if a Remote Computer is Up
LICENSE=	mit	# + file LICENSE

DEPENDS+=	R-processx>=3.8.1:../../sysutils/R-processx

# may conflict with tex-tetex-3.0.50602nb1
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
