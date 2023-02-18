# $NetBSD: Makefile,v 1.3 2023/02/18 09:29:34 mef Exp $

R_PKGNAME=	pingr
R_PKGVER=	2.0.2
CATEGORIES=	net

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Check if a Remote Computer is Up
LICENSE=	mit	# + file LICENSE

DEPENDS+=	R-processx>=3.4.1:../../sysutils/R-processx

# may conflict with tex-tetex-3.0.50602nb1
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
