# $NetBSD: Makefile,v 1.15 2002/03/11 09:00:25 skrll Exp $
#

DISTNAME=	gnut-0.4.20
CATEGORIES=	net
MASTER_SITES=	http://www.gnutelladev.com/source/gnut/

MAINTAINER=	deberg@netbsd.org
HOMEPAGE=	http://www.gnutelliums.com/linux_unix/gnut/
COMMENT=	Text-mode Gnutella client

DEPENDS+=	unproven-pthreads-0.*:../../devel/unproven-pthreads
CONFIGURE_ENV+=	CC=${LOCALBASE}/pthreads/bin/pgcc \
		CXX=${LOCALBASE}/pthreads/bin/pg++

GNU_CONFIGURE=	yes

GNUTDOCDIR=	${PREFIX}/share/doc/gnut

# Find <pthread.h>
.if make(do-configure)
LDFLAGS=	-Wl,-R${LOCALBASE}/pthreads/lib -L${LOCALBASE}/pthreads/lib
.endif

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
