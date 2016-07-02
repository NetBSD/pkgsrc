# $NetBSD: Makefile,v 1.17 2016/07/02 14:44:50 joerg Exp $

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

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mgcc)
CFLAGS+=	-Wno-error=unused-but-set-variable
.endif

.include "../../mk/bsd.pkg.mk"
