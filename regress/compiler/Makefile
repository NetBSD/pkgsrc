# $NetBSD: Makefile,v 1.8 2009/04/09 00:47:12 joerg Exp $
#

DISTNAME=	compiler-1.1
CATEGORIES=	regress
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Tests whether the pkgsrc compilers work as expected

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	c c++

do-extract:
	cd ${FILESDIR} && cp Makefile *.c ${WRKSRC}
	cd ${WRKSRC} && for i in *.c; do ln $$i $${i}c; done

do-wrksrc-build:

.include "../../mk/bsd.pkg.mk"
