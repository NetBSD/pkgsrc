# $NetBSD: Makefile,v 1.14 2001/11/29 19:46:13 jlam Exp $
#

DISTNAME=	gnut-0.4.20
CATEGORIES=	net
MASTER_SITES=	http://www.gnutelladev.com/source/gnut/

MAINTAINER=	deberg@netbsd.org
HOMEPAGE=	http://www.gnutelliums.com/linux_unix/gnut/
COMMENT=	Text-mode Gnutella client

#BUILD_DEPENDS+=	automake>=1.4:../../devel/automake
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
#	cd ${WRKSRC} && ${CP} aclocal.m4 acinclude.m4 && ${LOCALBASE}/bin/autoreconf

GNUTDOCS=	TUTORIAL \
		gnut-1.html \
		gnut-2.html \
		gnut-3.html \
		gnut-4.html \
		gnut-5.html \
		gnut-6.html \
		gnut.html

post-install:
	${INSTALL_DATA_DIR} ${GNUTDOCDIR}
	for i in ${GNUTDOCS}; do \
	    ${INSTALL_DATA} ${WRKSRC}/doc/$$i ${GNUTDOCDIR}; \
	done
	${INSTALL_DATA} ${WRKSRC}/gnutrc.sample ${GNUTDOCDIR}

.include "../../mk/bsd.pkg.mk"
