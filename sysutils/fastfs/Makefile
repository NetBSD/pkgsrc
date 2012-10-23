# $NetBSD: Makefile,v 1.6 2012/10/23 19:51:01 asau Exp $
#

DISTNAME=		fastfs.c
PKGNAME=		fastfs-19940614
CATEGORIES=		sysutils
MASTER_SITES=		http://www.squirrel.com/squirrel/
EXTRACT_SUFX=		# empty

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Turn on/off delayed IO on a file system

ONLY_FOR_PLATFORM=	SunOS-*-*

WRKSRC=			${WRKDIR}/fastfs
NO_CONFIGURE=		yes
INSTALLATION_DIRS=	sbin

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/${DISTNAME} ${WRKSRC}

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${DISTNAME} -o ${DISTNAME:S/.c//}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fastfs ${DESTDIR}${PREFIX}/sbin

.include "../../mk/bsd.pkg.mk"
