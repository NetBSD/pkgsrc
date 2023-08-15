# $NetBSD: Makefile,v 1.9 2023/08/15 01:19:39 mef Exp $

R_PKGNAME=	processx
R_PKGVER=	3.8.2
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Execute and control system processes
LICENSE=	mit

DEPENDS+=	R-R6>=2.4.0:../../devel/R-R6
DEPENDS+=	R-ps>=1.2.0:../../sysutils/R-ps

# Package suggested but not available: 'debugme'
#EST_DEPENDS+=	R-debugme-[0-9]*:../../?/R-debugme

USE_LANGUAGES=	c

LIBS.SunOS+=	-lsocket -lnsl

.include "../../math/R/Makefile.extension"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
