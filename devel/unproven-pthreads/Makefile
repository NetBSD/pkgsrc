# $NetBSD: Makefile,v 1.27 2001/11/29 01:12:30 hubertf Exp $
#

DISTNAME=		unproven-pthreads-0.17
PKGREVISION=		2
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.flame.org/pub/netbsd/

MAINTAINER=		explorer@netbsd.org
COMMENT=		(MIT) POSIX threads library, hacked by Michael Graff

ONLY_FOR_PLATFORM=	NetBSD-*-alpha NetBSD-*-arm32 NetBSD-*-i386 \
			NetBSD-*-m68k NetBSD-*-powerpc NetBSD-*-sparc
CONFLICTS+=		mit-pthreads-[0-9]*

HAS_CONFIGURE=		yes
MAKE_ENV+=		NOLINT=1 NOPROFILE=1 OBJECT_FMT=${OBJECT_FMT}
CONFIGURE_ARGS+=	--prefix=${PREFIX}/pthreads

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
