# $NetBSD: Makefile,v 1.121 2008/01/11 12:58:30 abs Exp $

DISTNAME=	cpuflags-1.18
CATEGORIES=	sysutils
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	abs@NetBSD.org
COMMENT=	Determine compiler flags to best target current cpu

ONLY_FOR_PLATFORM= NetBSD-*-* Linux-*-* SunOS-*-* FreeBSD-*-*

USE_LANGUAGES=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${FILESDIR}/Makefile ${WRKSRC}
	${CP} ${FILESDIR}/c* ${WRKSRC}
	${CP} ${FILESDIR}/o* ${WRKSRC}
	${CP} ${FILESDIR}/s* ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
