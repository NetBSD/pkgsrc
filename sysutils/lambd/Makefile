# $NetBSD: Makefile,v 1.1.1.1 2001/07/13 21:56:01 itojun Exp $

DISTNAME=	lambd-20010714
CATEGORIES=	sysutils
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	itojun@netbsd.org
COMMENT=	shutdown switch monitoring daemon for Wildlab LAMB

ONLY_FOR_PLATFORM=	NetBSD-*-i386

MAKE_ENV+=	BINDIR=${PREFIX}/sbin MANDIR=${PREFIX}/man

F=	lambd.c lambd.8 Makefile

do-extract:
	${MKDIR} ${WRKSRC}
	for i in ${F}; do \
		${CP} ${FILESDIR}/$$i ${WRKSRC}; \
	done

.include "../../mk/bsd.pkg.mk"
