# $NetBSD: Makefile,v 1.11 1998/08/20 15:16:48 tsarna Exp $
#

DISTNAME=		pthreads-1_60_beta6
PKGNAME=		mit-pthreads-1.60b6
CATEGORIES=		devel
MASTER_SITES=		ftp://sipb.mit.edu/pub/pthreads/
ONLY_FOR_ARCHS=		alpha arm32 i386 mips* pc532 powerpc sparc vax

MAINTAINER=		agc@netbsd.org
HOMEPAGE=		http://www.mit.edu:8001/people/proven/pthreads.html

HAS_CONFIGURE=		yes
MAKE_ENV+=		NOLINT=1
CONFIGURE_ARGS+=	--prefix=${PREFIX}/pthreads

pre-install:
	-mkdir ${PREFIX}/pthreads

post-install:
	find ${PREFIX}/pthreads/include -type f -print|xargs chmod 644
	find ${PREFIX}/pthreads/include -type d -print|xargs chmod 755

.include "../../mk/bsd.pkg.mk"
