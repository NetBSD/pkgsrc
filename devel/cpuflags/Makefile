# $NetBSD: Makefile,v 1.134 2008/12/21 15:49:27 abs Exp $

DISTNAME=	cpuflags-1.28
CATEGORIES=	devel sysutils
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	abs@NetBSD.org
COMMENT=	Determine compiler flags to best target current cpu

PKG_DESTDIR_SUPPORT=	user-destdir

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
