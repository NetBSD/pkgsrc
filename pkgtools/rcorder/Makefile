# $NetBSD: Makefile,v 1.17 2014/03/03 05:22:18 obache Exp $
#

PKGNAME=		rcorder-20120310
CATEGORIES=		pkgtools sysutils

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://www.NetBSD.org/
COMMENT=		Print a dependency ordering of interdependent files
LICENSE=		modified-bsd AND original-bsd

GNU_CONFIGURE=		yes
USE_FEATURES=		nbcompat

do-extract:
	${CP} -R ${FILESDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
