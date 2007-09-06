# $NetBSD: Makefile,v 1.10 2007/09/06 21:29:26 jlam Exp $
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

do-extract:
	${CP} -R ${FILESDIR} ${WRKSRC}

.include "../../pkgtools/libnbcompat/inplace.mk"
.include "../../mk/bsd.pkg.mk"
