# $NetBSD: Makefile,v 1.19 2001/01/09 16:14:20 briggs Exp $
#

DISTNAME=		unproven-pthreads-0.17
PKGNAME=		${DISTNAME}nb1
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.flame.org/pub/netbsd/

MAINTAINER=		explorer@netbsd.org

#ONLY_FOR_PLATFORM=	NetBSD-*-sparc
ONLY_FOR_PLATFORM=	NetBSD-*-alpha NetBSD-*-arm32 NetBSD-*-i386 \
			NetBSD-*-m68k NetBSD-*-powerpc
CONFLICTS+=		mit-pthreads-*

HAS_CONFIGURE=		yes
MAKE_ENV+=		NOLINT=1 NOPROFILE=1 OBJECT_FMT=${OBJECT_FMT}
CONFIGURE_ARGS+=	--prefix=${PREFIX}/pthreads

pre-install:
	${MKDIR} ${PREFIX}/pthreads

post-install:
	@${RM} -f ${PREFIX}/pthreads/lib/libpthread_pic.a
	@${FIND} ${PREFIX}/pthreads/include -name '*.orig'|xargs ${RM}
	@${FIND} ${PREFIX}/pthreads/include -type f -print|xargs ${CHMOD} 644
	@${FIND} ${PREFIX}/pthreads/include -type d -print|xargs ${CHMOD} 755
	@${CHOWN} -R ${BINOWN}:${BINGRP} ${PREFIX}/pthreads/include

.include "../../mk/bsd.pkg.mk"
