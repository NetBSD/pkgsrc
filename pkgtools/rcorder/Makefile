# $NetBSD: Makefile,v 1.18 2020/01/18 23:33:27 rillig Exp $
#

PKGNAME=		rcorder-20120310
CATEGORIES=		pkgtools sysutils

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://www.NetBSD.org/
COMMENT=		Print a dependency ordering of interdependent files
LICENSE=		modified-bsd AND original-bsd

GNU_CONFIGURE=		yes
USE_FEATURES=		nbcompat

do-extract:
	${CP} -R ${FILESDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
