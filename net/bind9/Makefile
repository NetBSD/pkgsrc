# $NetBSD: Makefile,v 1.26 2001/02/13 04:56:14 itojun Exp $
#

DISTNAME=	bind-${BIND_VERSION}
# trick to avoid version number issue - 9.1.1rc1 is prior to 9.1.1
PKGNAME=	bind-9.1.0.1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.isc.org/isc/bind9/${BIND_VERSION}/

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://www.isc.org/products/BIND/

# IPv6 ready, automatically detected
.include "../../mk/bsd.prefs.mk"
BUILD_DEFS+=	USE_INET6

# No need to set USE_INET6, will auto-detect.
BIND_VERSION=	9.1.1rc1
DIST_SUBDIR=	bind/${BIND_VERSION}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--disable-threads	# Until we have real threads
# dnssec-keygen needs "good enough" random number, use /dev/urandom
CONFIGURE_ARGS+=--with-libtool=yes \
		--sysconfdir=/etc \
		--localstatedir=/var \
		--with-randomdev=/dev/urandom
LDFLAGS+=	-Wl,-R${LOCALBASE}/pthreads/lib -L${LOCALBASE}/pthreads/lib
# use external OpenSSL.  comment the following two lines out to use
# OpenSSL shipped with BIND9.
# 9.1.1rc1 has errors in openssh include path determination.
#USE_SSL=	yes
#CONFIGURE_ARGS+=--with-openssl=${LOCALBASE}

post-build:
	${SED} \
		-e 's|@PREFIX@|${PREFIX}|' \
		<${FILESDIR}/named.sh >${WRKDIR}/named
	${SED} \
		-e 's|@PREFIX@|${PREFIX}|' \
		<${FILESDIR}/lwresd.sh >${WRKDIR}/lwresd

PLIST_SRC=	${WRKDIR}/PLIST

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
	${INSTALL_MAN} ${WRKSRC}/doc/man/bin/*.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/man/dnssec/*.8 ${PREFIX}/man/man8
	${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	(cd ${PREFIX}; ${FIND} share/doc/bind9 -type f -print ) >> ${PLIST_SRC}
	(cd ${PREFIX}; ${FIND} share/doc/bind9 -type d -print ) | \
		${SED} -e 's/^/@dirrm /' | sort -r >> ${PLIST_SRC}
	${INSTALL_DATA} ${WRKDIR}/named ${PREFIX}/etc/rc.d/named9
	${INSTALL_DATA} ${WRKDIR}/lwresd ${PREFIX}/etc/rc.d/lwresd

.include "../../mk/bsd.pkg.mk"
