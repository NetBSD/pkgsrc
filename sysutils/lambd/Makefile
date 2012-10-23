# $NetBSD: Makefile,v 1.16 2012/10/23 19:51:09 asau Exp $

DISTNAME=	lambd-20010719
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Shutdown switch monitoring daemon for Wildlab LAMB

ONLY_FOR_PLATFORM=	NetBSD-*-i386

USE_BSD_MAKEFILE=	yes
USE_TOOLS+=		groff nroff

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/cat8 ${PKGMANDIR}/man8

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${FILESDIR}/*.[ch8] ${WRKSRC}
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
