# $NetBSD: Makefile,v 1.29 2002/07/10 21:58:14 skrll Exp $
#

DISTNAME=		unproven-pthreads-0.17
PKGREVISION=		3
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.flame.org/pub/netbsd/

MAINTAINER=		explorer@netbsd.org
COMMENT=		(MIT) POSIX threads library, hacked by Michael Graff

ONLY_FOR_PLATFORM=	NetBSD-*-alpha NetBSD-*-arm32 NetBSD-*-i386 \
			NetBSD-*-m68k NetBSD-*-powerpc NetBSD-*-sparc
CONFLICTS+=		mit-pthreads-[0-9]*

GNU_CONFIGURE=		yes
GNU_CONFIGURE_PREFIX=	${PREFIX}/pthreads
MAKE_ENV+=		NOLINT=1 NOPROFILE=1 OBJECT_FMT=${OBJECT_FMT}

post-extract:
	@${RM} ${WRKSRC}/include/pthread/unistd.h

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/pthreads

post-install:
	@${RM} -f ${PREFIX}/pthreads/lib/libpthread_pic.a
	@${FIND} ${PREFIX}/pthreads/include -name '*.orig' | ${XARGS} ${RM}
	@${FIND} ${PREFIX}/pthreads/include -type f -print | ${XARGS} ${CHMOD} 644
	@${FIND} ${PREFIX}/pthreads/include -type d -print | ${XARGS} ${CHMOD} 755
	@${CHOWN} -R ${BINOWN}:${BINGRP} ${PREFIX}/pthreads/include

.include "../../mk/bsd.pkg.mk"
