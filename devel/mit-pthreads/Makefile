# $NetBSD: Makefile,v 1.17 1999/05/01 18:35:22 tron Exp $
#

DISTNAME=		pthreads-1_60_beta6
PKGNAME=		mit-pthreads-1.60b6
CATEGORIES=		devel
MASTER_SITES=		ftp://sipb.mit.edu/pub/pthreads/
ONLY_FOR_ARCHS=		alpha arm32 i386 sparc
ONLY_FOR_OPSYS=		NetBSD

MAINTAINER=		agc@netbsd.org
HOMEPAGE=		http://www.mit.edu:8001/people/proven/pthreads.html

HAS_CONFIGURE=		yes
MAKE_ENV+=		NOLINT=1 NOPROFILE=1
CONFIGURE_ARGS+=	--prefix=${PREFIX}/pthreads

pre-install:
	-mkdir ${PREFIX}/pthreads

post-install:
	@${RM} -f ${PREFIX}/pthreads/lib/libpthread_pic.a
	@find ${PREFIX}/pthreads/include -name '*.orig'|xargs rm
	@find ${PREFIX}/pthreads/include -type f -print|xargs chmod 644
	@find ${PREFIX}/pthreads/include -type d -print|xargs chmod 755
	@${CHOWN} -R ${BINOWN}:${BINGRP} ${PREFIX}/pthreads/include

.include "../../mk/bsd.pkg.mk"
