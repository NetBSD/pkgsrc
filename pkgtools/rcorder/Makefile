# $NetBSD: Makefile,v 1.3 2004/08/27 02:17:05 jlam Exp $
#

DISTNAME=		rcorder-20031013
CATEGORIES=		pkgtools
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://www.NetBSD.org/
COMMENT=		Print a dependency ordering of interdependent files

USE_BUILDLINK3=		yes

NO_CHECKSUM=		# defined
MANCOMPRESSED_IF_MANZ=	yes

do-extract:
	@${CP} -Rp ${FILESDIR} ${WRKSRC}

.include "../../pkgtools/libnbcompat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
