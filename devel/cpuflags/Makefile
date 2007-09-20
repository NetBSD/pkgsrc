# $NetBSD: Makefile,v 1.120 2007/09/20 10:19:03 abs Exp $

DISTNAME=	cpuflags-1.17
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
