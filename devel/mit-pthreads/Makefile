# $NetBSD: Makefile,v 1.8 1998/04/15 10:38:21 agc Exp $
#

DISTNAME=       pthreads-1_60_beta6
PKGNAME=        mit-pthreads-1.60b6
CATEGORIES=	devel
MASTER_SITES=   ftp://sipb.mit.edu/pub/pthreads/
ONLY_FOR_ARCHS=	alpha arm32 bebox i386 mips pc532 powerpc sparc vax

MAINTAINER=	agc@netbsd.org

GNU_CONFIGURE=	yes
MAKE_ENV+=	NOLINT=1

pre-install:
	-mkdir ${PREFIX}/pthreads

post-install:
	find ${PREFIX}/pthreads/include -type f -print|xargs chmod 644
	find ${PREFIX}/pthreads/include -type d -print|xargs chmod 755

.include "../../mk/bsd.pkg.mk"
