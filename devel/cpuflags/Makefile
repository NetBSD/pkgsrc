# $NetBSD: Makefile,v 1.118 2007/08/27 16:57:45 tron Exp $

DISTNAME=	cpuflags-1.15
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
	${CP} ${FILESDIR}/Makefile ${FILESDIR}/[a-z]* ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
