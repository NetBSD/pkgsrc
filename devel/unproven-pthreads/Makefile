# $NetBSD: Makefile,v 1.41 2004/04/25 06:02:54 snj Exp $
#

DISTNAME=		unproven-pthreads-0.17
PKGREVISION=		4
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.flame.org/pub/netbsd/

MAINTAINER=		explorer@NetBSD.org
COMMENT=		(MIT) POSIX threads library, hacked by Michael Graff

ONLY_FOR_PLATFORM=	NetBSD-*-alpha NetBSD-*-arm NetBSD-*-arm32 \
			NetBSD-*-i386 NetBSD-*-m68k NetBSD-*-powerpc \
			NetBSD-*-sparc
CONFLICTS+=		mit-pthreads-[0-9]*

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
GNU_CONFIGURE_PREFIX=	${PREFIX}/pthreads
MAKE_ENV+=		NOLINT=1 NOPROFILE=1 OBJECT_FMT=${OBJECT_FMT} USETOOLS=no

# Remove environment variables with special meaning from the shell
# environment before executing ${MAKE_PROGRAM} in the do-configure,
# do-build and do-install targets.
#
CLEAN_ENV_CMD+=		unset MAKEOBJDIR MAKEOBJDIRPREFIX || ${TRUE} ;

post-extract:
	@${RM} ${WRKSRC}/include/pthread/unistd.h

do-build:
	@${CLEAN_ENV_CMD}cd ${WRKSRC} && ${SETENV} ${MAKE_ENV}		\
		${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} ${ALL_TARGET}

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/pthreads

do-install:
	@${CLEAN_ENV_CMD}cd ${WRKSRC} && ${SETENV} ${MAKE_ENV}		\
		${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} ${INSTALL_TARGET}

post-install:
	@${RM} -f ${PREFIX}/pthreads/lib/libpthread_pic.a
	@${FIND} ${PREFIX}/pthreads/include -name '*.orig' -print | ${XARGS} ${RM}
	@${FIND} ${PREFIX}/pthreads/include -type f -print | ${XARGS} ${CHMOD} 644
	@${FIND} ${PREFIX}/pthreads/include -type d -print | ${XARGS} ${CHMOD} 755
	@${CHOWN} -R ${BINOWN}:${BINGRP} ${PREFIX}/pthreads/include

.include "../../mk/bsd.pkg.mk"
