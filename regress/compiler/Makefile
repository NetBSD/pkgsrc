# $NetBSD: Makefile,v 1.6 2007/09/25 10:03:53 hira Exp $
#

DISTNAME=	compiler-1.1
CATEGORIES=	regress
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	rillig@NetBSD.org
COMMENT=	Tests whether the pkgsrc compilers work as expected

NO_CHECKSUM=	yes
WRKSRC=		${WRKDIR}
USE_LANGUAGES=	c c++

do-extract:
	cd ${FILESDIR} && cp Makefile *.c ${WRKSRC}
	cd ${WRKSRC} && for i in *.c; do ln $$i $${i}c; done

do-wrksrc-build:

.include "../../mk/bsd.pkg.mk"
