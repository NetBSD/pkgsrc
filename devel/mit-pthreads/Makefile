# $NetBSD: Makefile,v 1.35 2002/06/23 03:44:49 jlam Exp $
#

DISTNAME=		pthreads-1_60_beta6
PKGNAME=		mit-pthreads-1.60b6
CATEGORIES=		devel
MASTER_SITES=		ftp://sipb.mit.edu/pub/pthreads/

MAINTAINER=		agc@netbsd.org
HOMEPAGE=		http://www.mit.edu:8001/people/proven/pthreads.html
COMMENT=		Chris Provenzano's (MIT) POSIX threads library

ONLY_FOR_PLATFORM=	NetBSD-*-alpha NetBSD-*-arm32 NetBSD-*-i386 \
			NetBSD-*-sparc NetBSD-*-m68k NetBSD-*-powerpc
CONFLICTS+=             unproven-pthreads-[0-9]*

GNU_CONFIGURE=		yes
GNU_CONFIGURE_PREFIX=	${PREFIX}/pthreads
MAKE_ENV+=		NOLINT=1 NOPROFILE=1 OBJECT_FMT=${OBJECT_FMT}

PATCH_FUZZ_FACTOR=	# empty

post-patch:
	@${RM} ${WRKSRC}/include/endian.h
	@${RM} ${WRKSRC}/include/math.h

post-configure:
	@${ECHO} "#define HAVE_SYSCALL_SIGACTION 1" >> ${WRKSRC}/config.h
	@${ECHO} "#define HAVE_SYSCALL_SIGPAUSE 1" >> ${WRKSRC}/config.h
	@${ECHO} "#define HAVE_SYSCALL_SIGPROCMASK 1" >> ${WRKSRC}/config.h
	@${ECHO} "#define HAVE_SYSCALL_SIGSUSPEND 1" >> ${WRKSRC}/config.h
	@${RM} ${WRKSRC}/include/sys/__math.h

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/pthreads

post-install:
	@${RM} -f ${PREFIX}/pthreads/lib/libpthread_pic.a
	@${FIND} ${PREFIX}/pthreads/include -name '*.orig' | ${XARGS} ${RM}
	@${FIND} ${PREFIX}/pthreads/include -type f -print | ${XARGS} ${CHMOD} 644
	@${FIND} ${PREFIX}/pthreads/include -type d -print | ${XARGS} ${CHMOD} 755
	@${CHOWN} -R ${BINOWN}:${BINGRP} ${PREFIX}/pthreads/include

.include "../../mk/bsd.pkg.mk"
