# $NetBSD: Makefile,v 1.28 2000/03/16 12:27:04 wiz Exp $
#

DISTNAME=		pthreads-1_60_beta6
PKGNAME=		mit-pthreads-1.60b6
CATEGORIES=		devel
MASTER_SITES=		ftp://sipb.mit.edu/pub/pthreads/

MAINTAINER=		agc@netbsd.org
HOMEPAGE=		http://www.mit.edu:8001/people/proven/pthreads.html

ONLY_FOR_PLATFORM=	NetBSD-*-alpha NetBSD-*-arm32 NetBSD-*-i386 \
			NetBSD-*-sparc NetBSD-*-m68k
CONFLICTS+=             unproven-pthreads-*

HAS_CONFIGURE=		yes
MAKE_ENV+=		NOLINT=1 NOPROFILE=1 OBJECT_FMT=${OBJECT_FMT}
CONFIGURE_ARGS+=	--prefix=${PREFIX}/pthreads

PATCH_FUZZ_FACTOR=

post-patch:
	@${RM} ${WRKSRC}/include/endian.h

post-configure:
	@${ECHO} "#define HAVE_SYSCALL_SIGACTION 1" >> ${WRKSRC}/config.h
	@${ECHO} "#define HAVE_SYSCALL_SIGPAUSE 1" >> ${WRKSRC}/config.h
	@${ECHO} "#define HAVE_SYSCALL_SIGPROCMASK 1" >> ${WRKSRC}/config.h
	@${ECHO} "#define HAVE_SYSCALL_SIGSUSPEND 1" >> ${WRKSRC}/config.h

pre-install:
	${MKDIR} ${PREFIX}/pthreads

post-install:
	@${RM} -f ${PREFIX}/pthreads/lib/libpthread_pic.a
	@${FIND} ${PREFIX}/pthreads/include -name '*.orig'|xargs ${RM}
	@${FIND} ${PREFIX}/pthreads/include -type f -print|xargs ${CHMOD} 644
	@${FIND} ${PREFIX}/pthreads/include -type d -print|xargs ${CHMOD} 755
	@${CHOWN} -R ${BINOWN}:${BINGRP} ${PREFIX}/pthreads/include

.include "../../mk/bsd.pkg.mk"
