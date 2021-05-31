# $NetBSD: Makefile,v 1.4 2021/05/31 14:26:12 mef Exp $

R_PKGNAME=	processx
R_PKGVER=	3.5.2
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Execute and control system processes
LICENSE=	mit

DEPENDS+=	R-R6>=2.4.0:../../devel/R-R6
DEPENDS+=	R-ps>=1.2.0:../../sysutils/R-ps

# Package suggested but not available: 'debugme'
#EST_DEPENDS+=	R-debugme-[0-9]*:../../?/R-debugme

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
