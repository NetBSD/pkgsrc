# $NetBSD: Makefile,v 1.2 2001/07/13 23:12:18 itojun Exp $

DISTNAME=	lambd-20010714
CATEGORIES=	sysutils
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	itojun@netbsd.org
COMMENT=	shutdown switch monitoring daemon for Wildlab LAMB

EXTRACT_ONLY=	# none
NO_CHECKSUM=	yes

ONLY_FOR_PLATFORM=	NetBSD-*-i386

MAKE_ENV+=	BINDIR=${PREFIX}/sbin MANDIR=${PREFIX}/man

F=	lambd.c lambd.8 Makefile

do-extract:
	${MKDIR} ${WRKSRC}
	for i in ${F}; do \
		${CP} ${FILESDIR}/$$i ${WRKSRC}; \
	done

.include "../../mk/bsd.pkg.mk"
