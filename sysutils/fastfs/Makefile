# $NetBSD: Makefile,v 1.2 2005/06/17 03:50:34 jlam Exp $
#

DISTNAME=		fastfs.c
PKGNAME=		fastfs-19940614
CATEGORIES=		sysutils
MASTER_SITES=		http://www.squirrel.com/squirrel/
EXTRACT_SUFX=		# empty

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Turn on/off delayed IO on a file system

ONLY_FOR_PLATFORM=	SunOS-*-*

WRKSRC=			${WRKDIR}/fastfs
NO_CONFIGURE=		# defined
INSTALLATION_DIRS=	sbin

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/${DISTNAME} ${WRKSRC}

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${DISTNAME} -o ${DISTNAME:S/.c//}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${DISTNAME:S/.c//} ${PREFIX}/sbin

.include "../../mk/bsd.pkg.mk"
