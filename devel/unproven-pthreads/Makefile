# $NetBSD: Makefile,v 1.4 1999/12/02 20:13:24 explorer Exp $
#

DISTNAME=		unproven-pthreads-0.8
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.flame.org/pub/netbsd/

MAINTAINER=		explorer@netbsd.org
#HOMEPAGE=		http://www.mit.edu:8001/people/proven/pthreads.html

#ONLY_FOR_PLATFORM=	NetBSD-*-alpha NetBSD-*-sparc NetBSD-*-m68k
ONLY_FOR_PLATFORM=	NetBSD-*-i386 NetBSD-*-arm32

HAS_CONFIGURE=		yes
MAKE_ENV+=		NOLINT=1 NOPROFILE=1 OBJECT_FMT=${OBJECT_FMT}
CONFIGURE_ARGS+=	--prefix=${PREFIX}/pthreads

pre-install:
	${MKDIR} ${PREFIX}/pthreads

post-install:
	@${RM} -f ${PREFIX}/pthreads/lib/libpthread_pic.a
	@find ${PREFIX}/pthreads/include -name '*.orig'|xargs rm
	@find ${PREFIX}/pthreads/include -type f -print|xargs chmod 644
	@find ${PREFIX}/pthreads/include -type d -print|xargs chmod 755
	@${CHOWN} -R ${BINOWN}:${BINGRP} ${PREFIX}/pthreads/include

.include "../../mk/bsd.pkg.mk"
