# $NetBSD: Makefile,v 1.1.1.1 2002/01/15 13:20:27 agc Exp $
#

DISTNAME=	shlock-20020114
CATEGORIES=	pkgtools sysutils
MASTER_SITES=	#

MAINTAINER=	packages@netbsd.org
#HOMEPAGE=
COMMENT=	shell utility to perform dot-locking

ONLY_FOR_PLATFORM=	SunOS-*-* Linux-*-*

EXTRACT_ONLY=	#empty
WRKSRC=		${WRKDIR}
NO_CHECKSUM=	#defined
MANCOMPRESSED_IF_MANZ=	yes
PLIST_SRC=	${WRKDIR}/PLIST
BUILD_DEFS+=	MANINSTALL

MAKE_ENV+=	BINDIR=${LOCALBASE}/bin MANDIR=${LOCALBASE}/man

post-extract:
	@for FILE in Makefile shlock.c shlock.1; do			\
		${CP} ${FILESDIR}/$$FILE ${WRKSRC};			\
	done

pre-install:
	@${RM} -f ${PLIST_SRC}
	@${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	@if [ -n "${MANINSTALL:Mcatinstall}" ]; then			\
		${ECHO} man/cat1/shlock.0 >> ${PLIST_SRC};		\
	fi
	@if [ -n "${MANINSTALL:Mmaninstall}" ]; then			\
		${ECHO} man/man1/shlock.1 >> ${PLIST_SRC};		\
	fi

.include "../../mk/bsd.pkg.mk"
