# $NetBSD: Makefile,v 1.1.1.1 2000/02/22 03:50:57 hubertf Exp $
#

DISTNAME=	bind-9.0.0b1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.isc.org/isc/bind9/9.0.0b1/

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://www.isc.org/products/BIND/

DEPENDS+=	unproven-pthreads-0.*:../../devel/unproven-pthreads

# No need to set USE_INET6, will auto-detect.
DIST_SUBDIR=	bind/9.0.0b1
GNU_CONFIGURE=	yes
PLIST_SRC=	${WRKDIR}/newPLIST
CONFIGURE_ARGS+=--with-mit-pthreads \
		--with-libtool=yes
CONFIGURE_ENV+=	CC=${LOCALBASE}/pthreads/bin/pgcc \
		CXX=${LOCALBASE}/pthreads/bin/pg++

post-install:
	${MKDIR} ${PREFIX}/share/doc/bind9
	${MKDIR} ${PREFIX}/share/doc/bind9/arm
	${MKDIR} ${PREFIX}/share/doc/bind9/draft
	${MKDIR} ${PREFIX}/share/doc/bind9/misc
	${MKDIR} ${PREFIX}/share/doc/bind9/rfc
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/bind9
	${INSTALL_DATA} ${WRKSRC}/doc/arm/* ${PREFIX}/share/doc/bind9/arm
	${INSTALL_DATA} ${WRKSRC}/doc/draft/* ${PREFIX}/share/doc/bind9/draft
	${INSTALL_DATA} ${WRKSRC}/doc/misc/* ${PREFIX}/share/doc/bind9/misc
	${INSTALL_DATA} ${WRKSRC}/doc/rfc/* ${PREFIX}/share/doc/bind9/rfc
	${INSTALL_PROGRAM} ${WRKSRC}/bin/rndc/rndc ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/lwresd/lwresd ${PREFIX}/sbin
	${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	(cd ${PREFIX}; \
	 ${FIND} share/doc/bind9 \( -type f -or -type l \) | \
	   sort >> ${PLIST_SRC}; \
	 for DIR in `${FIND} share/doc/bind9 -type d | sort -r`; do \
	   ${ECHO} "@dirrm $$DIR" >> ${PLIST_SRC}; \
	 done)

.include "../../mk/bsd.pkg.mk"
