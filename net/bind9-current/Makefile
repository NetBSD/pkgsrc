# $NetBSD: Makefile,v 1.30 2001/11/08 01:26:33 itojun Exp $
#

DISTNAME=	bind-${BIND_VERSION}
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.isc.org/isc/bind9/${BIND_VERSION}/

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://www.isc.org/products/BIND/
COMMENT=	Version 9 of the Berkeley Internet Name Daemon, implementation of DNS

# IPv6 ready, automatically detected
.include "../../mk/bsd.prefs.mk"
BUILD_DEFS+=	USE_INET6

# No need to set USE_INET6, will auto-detect.
BIND_VERSION=	9.2.0rc9
DIST_SUBDIR=	bind/${BIND_VERSION}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--disable-threads	# Until we have real threads
CONFIGURE_ARGS+=--with-libtool=yes \
		--sysconfdir=/etc \
		--localstatedir=/var
#LDFLAGS+=	-Wl,-R${LOCALBASE}/pthreads/lib -L${LOCALBASE}/pthreads/lib
# use external OpenSSL.  comment the following two lines out to use
# OpenSSL shipped with BIND9.
USE_SSL=	yes
CONFIGURE_ARGS+=--with-openssl=${LOCALBASE}

post-build:
	${SED} \
		-e 's|@PREFIX@|${PREFIX}|' \
		<${FILESDIR}/named.sh >${WRKDIR}/named
	${SED} \
		-e 's|@PREFIX@|${PREFIX}|' \
		<${FILESDIR}/lwresd.sh >${WRKDIR}/lwresd

PLIST_SRC=	${WRKDIR}/PLIST

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/bind9
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/bind9/arm
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/bind9/draft
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/bind9/misc
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/bind9/rfc
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/bind9
	${INSTALL_DATA} ${WRKSRC}/doc/arm/* ${PREFIX}/share/doc/bind9/arm
	${INSTALL_DATA} ${WRKSRC}/doc/draft/* ${PREFIX}/share/doc/bind9/draft
	${INSTALL_DATA} ${WRKSRC}/doc/misc/* ${PREFIX}/share/doc/bind9/misc
	${INSTALL_DATA} ${WRKSRC}/doc/rfc/* ${PREFIX}/share/doc/bind9/rfc
	${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	(cd ${PREFIX}; ${FIND} share/doc/bind9 -type f -print ) >> ${PLIST_SRC}
	(cd ${PREFIX}; ${FIND} share/doc/bind9 -type d -print ) | \
		${SED} -e 's/^/@dirrm /' | sort -r >> ${PLIST_SRC}
	${INSTALL_DATA} ${WRKDIR}/named ${PREFIX}/etc/rc.d/named9
	${INSTALL_DATA} ${WRKDIR}/lwresd ${PREFIX}/etc/rc.d/lwresd

.include "../../mk/bsd.pkg.mk"
