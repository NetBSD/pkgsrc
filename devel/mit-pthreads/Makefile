# $NetBSD: Makefile,v 1.14 1999/04/15 13:56:01 tv Exp $
#

DISTNAME=		pthreads-1_60_beta6
PKGNAME=		mit-pthreads-1.60b6
CATEGORIES=		devel
MASTER_SITES=		ftp://sipb.mit.edu/pub/pthreads/
ONLY_FOR_ARCHS=		alpha arm32 i386 sparc
ONLY_FOR_OPSYS=		NetBSD

MAINTAINER=		agc@netbsd.org
HOMEPAGE=		http://www.mit.edu:8001/people/proven/pthreads.html

# don't build unless the user explicitly builds it
RESTRICTED=		"broken on later 1.3 development versions and 1.4"
IS_INTERACTIVE=		yes

HAS_CONFIGURE=		yes
MAKE_ENV+=		NOLINT=1 NOPROFILE=1
CONFIGURE_ARGS+=	--prefix=${PREFIX}/pthreads

post-patch:
	@cd ${WRKSRC}/machdep && for i in *-netbsd-1.3.?; do \
		${LN} -f $$i `echo $$i | sed s,1\.3,1.4,`; \
	done

pre-install:
	-mkdir ${PREFIX}/pthreads

post-install:
	@${RM} -f ${LOCALBASE}/pthreads/libpthread_pic.a
	find ${PREFIX}/pthreads/include -name '*.orig'|xargs rm
	find ${PREFIX}/pthreads/include -type f -print|xargs chmod 644
	find ${PREFIX}/pthreads/include -type d -print|xargs chmod 755

.include "../../mk/bsd.pkg.mk"
