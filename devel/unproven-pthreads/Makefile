# $NetBSD: Makefile,v 1.9 2000/01/27 09:30:18 explorer Exp $
#

DISTNAME=		unproven-pthreads-0.11
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.flame.org/pub/netbsd/

MAINTAINER=		explorer@netbsd.org
#HOMEPAGE=		http://www.mit.edu:8001/people/proven/pthreads.html

#ONLY_FOR_PLATFORM=	NetBSD-*-alpha NetBSD-*-sparc
ONLY_FOR_PLATFORM=	NetBSD-*-i386 NetBSD-*-arm32 NetBSD-*-m68k

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
