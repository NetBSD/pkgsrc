# $NetBSD: Makefile,v 1.7 2001/02/05 09:01:01 tron Exp $
#

DISTNAME=	gnut-0.4.12
CATEGORIES=	net
MASTER_SITES=	http://www.mrob.com/gnut/tars/

MAINTAINER=	deberg@netbsd.org
HOMEPAGE=	http://www.mrob.com/gnut/

#BUILD_DEPENDS+=	${LOCALBASE}/bin/autoremake:../../devel/autoconf
#BUILD_DEPENDS+=	${LOCALBASE}/bin/automake:../../devel/automake
#DEPENDS+=	pth>=1.3.6:../../devel/pth

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
#	cd ${WRKSRC} && ${CP} aclocal.m4 acinclude.m4 && ${LOCALBASE}/bin/autoremake

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
