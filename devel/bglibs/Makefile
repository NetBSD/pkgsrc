# $NetBSD: Makefile,v 1.1.1.1 2004/12/21 00:12:29 schmonz Exp $
#

DISTNAME=		bglibs-1.019
CATEGORIES=		devel
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://untroubled.org/bglibs/
COMMENT=		Collection of libraries by Bruce Guenter

USE_BUILDLINK3=		yes

do-configure:
	${ECHO} ${CC} ${CFLAGS} > ${WRKSRC}/conf-cc
	${ECHO} ${CC} ${_STRIPFLAG_CC} > ${WRKSRC}/conf-ld
	${ECHO} ${PREFIX} > ${WRKSRC}/conf-home

do-install:
	cd ${WRKSRC} && ./installer && ./instcheck

.include "../../mk/bsd.pkg.mk"
