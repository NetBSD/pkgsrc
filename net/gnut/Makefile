# $NetBSD: Makefile,v 1.4 2000/08/12 15:12:40 deberg Exp $
#

DISTNAME=	gnut-0.4.12
CATEGORIES=	net
MASTER_SITES=	http://www.mrob.com/gnut/tars/

MAINTAINER=	deberg@netbsd.org
HOMEPAGE=	http://www.mrob.com/gnut/

#BUILD_DEPENDS+=	autoreconf:../../devel/autoconf
#BUILD_DEPENDS+=	automake:../../devel/automake
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

#post-patch:
#	cd ${WRKSRC} && ${CP} aclocal.m4 acinclude.m4 && autoreconf

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
