# $NetBSD: Makefile,v 1.1.1.1 2000/12/15 18:41:50 itojun Exp $
#

DISTNAME=	bind-${BIND_VERSION}
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.isc.org/isc/bind9/${BIND_VERSION}/

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://www.isc.org/products/BIND/

DEPENDS+=	unproven-pthreads>=0.17:../../devel/unproven-pthreads

# IPv6 ready, automatically detected
.include "../../mk/bsd.prefs.mk"
BUILD_DEFS+=	USE_INET6

# Sync these with devel/unproven-pthreads:
ONLY_FOR_PLATFORM=      NetBSD-*-i386 NetBSD-*-arm32 NetBSD-*-m68k

# No need to set USE_INET6, will auto-detect.
BIND_VERSION=	9.1.0b1
DIST_SUBDIR=	bind/${BIND_VERSION}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-mit-pthreads \
		--with-libtool=yes \
		--sysconfdir=/etc \
		--localstatedir=/var
LDFLAGS+=	-Wl,-R${LOCALBASE}/pthreads/lib -L${LOCALBASE}/pthreads/lib

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
	${INSTALL_MAN} ${WRKSRC}/doc/man/bin/*.8 ${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/doc/man/bin/*.5 ${PREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/doc/man/dnssec/*.8 ${PREFIX}/man/man8

.include "../../mk/bsd.pkg.mk"
