# $NetBSD: Makefile,v 1.50 2003/09/20 12:50:24 itojun Exp $
#

DISTNAME=	bind-${BIND_VERSION}-P2
PKGNAME=	bind-${BIND_VERSION}p2
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.isc.org/isc/bind9/${BIND_VERSION}-P2/

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://www.isc.org/products/BIND/
COMMENT=	Version 9 of the Berkeley Internet Name Daemon, implementation of DNS

BIND_VERSION=	9.2.2
DIST_SUBDIR=	bind/${BIND_VERSION}

# IPv6 ready, automatically detected
.include "../../mk/bsd.prefs.mk"
BUILD_DEFS+=	USE_INET6
# No need to set USE_INET6, will auto-detect.

USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE+=	${WRKSRC}/libtool
LIBTOOL_OVERRIDE+=	${WRKSRC}/lib/bind/libtool

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-libtool=yes \
		--sysconfdir=/etc \
		--localstatedir=/var
#LDFLAGS+=	-Wl,${RPATH_FLAG}${LOCALBASE}/pthreads/lib -L${LOCALBASE}/pthreads/lib
# use external OpenSSL.  comment out the following line and the buildlink
# include at the bottom to use OpenSSL shipped with BIND9.
CONFIGURE_ARGS+=--with-openssl=${SSLBASE}

PTHREAD_OPTS+=	native

post-build:
	${SED} \
		-e 's|@PREFIX@|${PREFIX}|' \
		<${FILESDIR}/named.sh >${WRKDIR}/named
	${SED} \
		-e 's|@PREFIX@|${PREFIX}|' \
		<${FILESDIR}/lwresd.sh >${WRKDIR}/lwresd

# include/isc/ipv6.h is installed on non-ipv6 platforms
.if defined(USE_INET6) && (${USE_INET6} == "YES")
IPV6H=		"@comment "
.else
IPV6H=		""
.endif

PLIST_SUBST+=	IPV6H=${IPV6H}
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
		${SED} -e 's/^/@dirrm /' | ${SORT} -r >> ${PLIST_SRC}
	${INSTALL_SCRIPT} ${WRKDIR}/named ${PREFIX}/etc/rc.d/named9
	${INSTALL_SCRIPT} ${WRKDIR}/lwresd ${PREFIX}/etc/rc.d/lwresd

.include "../../mk/pthread.buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "none")
CONFIGURE_ARGS+=	--disable-threads
.else
CONFIGURE_ARGS+=	--enable-threads
.endif
