# $NetBSD: Makefile,v 1.3 2000/07/16 18:17:30 kim Exp $
#

DISTNAME=	gnut-0.3.29
CATEGORIES=	net
MASTER_SITES=	http://www.umr.edu/~jjp/

MAINTAINER=	deberg@netbsd.org
HOMEPAGE=	http://www.umr.edu/~jjp/

BUILD_DEPENDS+=	autoreconf:../../devel/autoconf
#DEPENDS+=	pth>=1.3.6:../../devel/pth

# Sync these with devel/unproven-pthreads:
ONLY_FOR_PLATFORM=	NetBSD-*-i386 NetBSD-*-arm32 NetBSD-*-m68k
DEPENDS+=	unproven-pthreads-0.*:../../devel/unproven-pthreads
CONFIGURE_ENV+=	CC=${LOCALBASE}/pthreads/bin/pgcc \
		CXX=${LOCALBASE}/pthreads/bin/pg++

GNU_CONFIGURE=	yes

GNUTDOCDIR=	${PREFIX}/share/doc/gnut

# Find <pthread.h>
#.if make(do-configure)
#CFLAGS+=	-I${LOCALBASE}/include
#.endif

.if make(do-configure)
LDFLAGS=	-Wl,-R${LOCALBASE}/pthreads/lib -L${LOCALBASE}/pthreads/lib
.endif

post-patch:
	cd ${WRKSRC} && autoreconf

GNUTDOCS=	TUTORIAL \
		gnut-1.html \
		gnut-2.html \
		gnut-3.html \
		gnut-4.html \
		gnut-5.html \
		gnut-6.html \
		gnut.html

post-install:
	${MKDIR} ${GNUTDOCDIR}
	for i in ${GNUTDOCS}; do \
	    ${INSTALL_DATA} ${WRKSRC}/doc/$$i ${GNUTDOCDIR}; \
	done
	${INSTALL_DATA} ${WRKSRC}/gnutrc.sample ${GNUTDOCDIR}

.include "../../mk/bsd.pkg.mk"
