# $NetBSD: Makefile,v 1.15 2012/09/11 23:19:39 asau Exp $
#

DISTNAME=		rcorder-20120310
CATEGORIES=		pkgtools sysutils
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://www.NetBSD.org/
COMMENT=		Print a dependency ordering of interdependent files

GNU_CONFIGURE=		yes
USE_FEATURES=		nbcompat

do-extract:
	${CP} -R ${FILESDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
