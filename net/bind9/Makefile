# $NetBSD: Makefile,v 1.6 2000/04/28 06:43:00 itojun Exp $
#

DISTNAME=	bind-9.0.0b2
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.isc.org/isc/bind9/9.0.0b2/

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://www.isc.org/products/BIND/

# IPv6 ready, automatically detected
.include "../../mk/bsd.prefs.mk"
BUILD_DEFS+=	USE_INET6

# Sync these with devel/unproven-pthreads:
ONLY_FOR_PLATFORM=      NetBSD-*-i386 NetBSD-*-arm32 NetBSD-*-m68k

DEPENDS+=	unproven-pthreads-0.*:../../devel/unproven-pthreads

# No need to set USE_INET6, will auto-detect.
DIST_SUBDIR=	bind/9.0.0b2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-mit-pthreads \
		--with-libtool=yes \
		--sysconfdir=/etc \
		--localstatedir=/var
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
	${INSTALL_SCRIPT} ${WRKSRC}/bin/rndc/rndc ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/lwresd/lwresd ${PREFIX}/sbin

.include "../../mk/bsd.pkg.mk"
