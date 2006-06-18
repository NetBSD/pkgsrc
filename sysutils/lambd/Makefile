# $NetBSD: Makefile,v 1.10 2006/06/18 16:16:09 rillig Exp $

DISTNAME=	lambd-20010719
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	itojun@NetBSD.org
COMMENT=	Shutdown switch monitoring daemon for Wildlab LAMB

EXTRACT_ONLY=	# none
NO_CHECKSUM=	yes

ONLY_FOR_PLATFORM=	NetBSD-*-i386

MAKE_ENV+=	BINDIR=${PREFIX}/sbin MANDIR=${PREFIX}/man
MAKE_ENV+=	BINOWN=${BINOWN} BINGRP=${BINGRP}
MAKE_ENV+=	MANOWN=${MANOWN} MANGRP=${MANGRP}

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${FILESDIR}/*.[ch8] ${WRKSRC}
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
