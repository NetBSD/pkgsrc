# $NetBSD: Makefile,v 1.21 1999/07/29 16:44:41 bad Exp $
#

DISTNAME=		pthreads-1_60_beta6
PKGNAME=		mit-pthreads-1.60b6
CATEGORIES=		devel
MASTER_SITES=		ftp://sipb.mit.edu/pub/pthreads/

MAINTAINER=		agc@netbsd.org
HOMEPAGE=		http://www.mit.edu:8001/people/proven/pthreads.html

ONLY_FOR_PLATFORM=	NetBSD-*-alpha NetBSD-*-arm32 NetBSD-*-i386 \
			NetBSD-*-sparc NetBSD-*-m68k

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
