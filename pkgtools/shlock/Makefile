# $NetBSD: Makefile,v 1.8 2005/01/18 22:37:04 tv Exp $
#

DISTNAME=	shlock-20020114
CATEGORIES=	pkgtools sysutils
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg@NetBSD.org
#HOMEPAGE=
COMMENT=	Shell utility to perform dot-locking

ONLY_FOR_PLATFORM=	SunOS-*-* Linux-*-* Interix-*-*

WRKSRC=		${WRKDIR}
EXTRACT_ONLY=	#empty
NO_CHECKSUM=	#defined
MANCOMPRESSED_IF_MANZ=	yes
PLIST_SRC=	${WRKDIR}/PLIST
BUILD_DEFS+=	MANINSTALL

MAKE_ENV+=	BINDIR=${LOCALBASE}/bin MANDIR=${LOCALBASE}/man

.include "../../mk/bsd.prefs.mk"

PKGSRC_LOCKTYPE=	none	# avoid "bootstrapping problem"

.if ${OPSYS} == "SunOS"
MANINSTALL=
.endif

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
