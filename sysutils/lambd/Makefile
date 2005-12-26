# $NetBSD: Makefile,v 1.7 2005/12/26 23:39:34 schmonz Exp $

DISTNAME=	lambd-20010719
CATEGORIES=	sysutils
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	itojun@NetBSD.org
COMMENT=	Shutdown switch monitoring daemon for Wildlab LAMB

PKG_FAIL_REASON+=	"Broken on NetBSD/i386 3.0 in pkgsrc-2005Q4"
PKG_FAIL_REASON+=	"Will be removed in pkgsrc-2006Q1 unless fixed"

EXTRACT_ONLY=	# none
NO_CHECKSUM=	yes

ONLY_FOR_PLATFORM=	NetBSD-*-i386

MAKE_ENV+=	BINDIR=${PREFIX}/sbin MANDIR=${PREFIX}/man

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${FILESDIR}/*.[ch8] ${WRKSRC}
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
