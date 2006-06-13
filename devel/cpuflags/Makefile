# $NetBSD: Makefile,v 1.103 2006/06/13 09:56:00 abs Exp $
#

DISTNAME=	cpuflags-1.00
CATEGORIES=	sysutils
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	abs@NetBSD.org
COMMENT=	Determine compiler flags to best target current cpu

ONLY_FOR_PLATFORM= NetBSD-*-* Linux-*-* SunOS-*-*

USE_LANGUAGES=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${FILESDIR}/Makefile ${FILESDIR}/*.* ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
