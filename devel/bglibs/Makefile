# $NetBSD: Makefile,v 1.2 2005/03/13 03:25:43 schmonz Exp $
#

DISTNAME=		bglibs-1.019
CATEGORIES=		devel
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://untroubled.org/bglibs/
COMMENT=		Collection of libraries by Bruce Guenter

USE_BUILDLINK3=		yes

do-configure:
	${ECHO} ${CC:Q} ${CFLAGS:Q} > ${WRKSRC}/conf-cc
	${ECHO} ${CC:Q} ${_STRIPFLAG_CC} > ${WRKSRC}/conf-ld
	${ECHO} ${PREFIX} > ${WRKSRC}/conf-home

do-install:
	cd ${WRKSRC} && ./installer && ./instcheck

.include "../../mk/bsd.pkg.mk"
