# $NetBSD: Makefile,v 1.12 2007/12/31 03:09:31 obache Exp $

DISTNAME=	lambd-20010719
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Shutdown switch monitoring daemon for Wildlab LAMB

EXTRACT_ONLY=	# none
NO_CHECKSUM=	yes

ONLY_FOR_PLATFORM=	NetBSD-*-i386

PKG_DESTDIR_SUPPORT=	user-destdir

USE_BSD_MAKEFILE=	yes

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/cat8 ${PKGMANDIR}/man8

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${FILESDIR}/*.[ch8] ${WRKSRC}
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
