# $NetBSD: Makefile,v 1.11 2007/09/08 21:58:00 jlam Exp $
#

DISTNAME=		rcorder-20031013
CATEGORIES=		pkgtools sysutils
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://www.NetBSD.org/
COMMENT=		Print a dependency ordering of interdependent files

NO_CHECKSUM=		yes
GNU_CONFIGURE=		yes
USE_FEATURES=		nbcompat

do-extract:
	${CP} -R ${FILESDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
