# $NetBSD: Makefile,v 1.88 2007/05/02 08:12:37 cjs Exp $

DISTNAME=	bind-${BIND_VERSION}
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.isc.org/isc/bind9/${BIND_VERSION}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.isc.org/sw/bind/
COMMENT=	Version 9 of the Berkeley Internet Name Daemon, implementation of DNS

BIND_VERSION=	9.4.1

# IPv6 ready, automatically detected
.include "../../mk/bsd.prefs.mk"
BUILD_DEFS+=	USE_INET6
# No need to set USE_INET6, will auto-detect.

BUILD_DEFS+=	BIND_USER BIND_GROUP BIND_DIR VARBASE

USE_LIBTOOL=		yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-libtool=yes \
		--sysconfdir=/etc \
		--localstatedir=${VARBASE:Q}
#LDFLAGS+=	${COMPILER_RPATH_FLAG}${LOCALBASE}/pthreads/lib -L${LOCALBASE}/pthreads/lib
# use external OpenSSL.  comment out the following line and the buildlink
# include at the bottom to use OpenSSL shipped with BIND9.
CONFIGURE_ARGS+=--with-openssl=${SSLBASE:Q}

PKG_GROUPS=	${BIND_GROUP}
PKG_USERS=	${BIND_USER}:${BIND_GROUP}

PKG_GECOS.${BIND_USER}=	Named pseudo-user
PKG_HOME.${BIND_USER}=	${BIND_DIR}

PTHREAD_OPTS+=	native

FILES_SUBST+=	BIND_GROUP=${BIND_GROUP:Q} BIND_USER=${BIND_USER:Q} PAX=${PAX:Q}
MESSAGE_SUBST+=	BIND_DIR=${BIND_DIR} BIND_USER=${BIND_USER}

# include/isc/ipv6.h is installed on non-ipv6 platforms
.if defined(USE_INET6) && (${USE_INET6} == "YES")
PLIST_SUBST+=	IPV6H="@comment "
.else
PLIST_SUBST+=	IPV6H=
.endif

PLIST_SRC=	${WRKDIR}/PLIST
RCD_SCRIPTS=	lwresd named9

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/bind9
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/bind9/arm
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/bind9/draft
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/bind9/misc
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/bind9/rfc
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/bind9
	set -e; cd ${WRKSRC}/doc && ${PAX} -rwppm			\
	  -s ',.*xsl.*,,' -s ',Makefile.*,,' -s ',.*\.pl,,'		\
	  . ${PREFIX}/share/doc/bind9
	${CHMOD} -R g-w ${PREFIX}/share/doc/bind9
	${CHMOD} -x ${PREFIX}/share/doc/bind9/arm/Bv9ARM.pdf
	${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	(cd ${PREFIX}; ${FIND} share/doc/bind9 -type f -print ) >> ${PLIST_SRC}
	(cd ${PREFIX}; ${FIND} share/doc/bind9 -type d -print ) | \
		${SED} -e 's/^/@dirrm /' | ${SORT} -r >> ${PLIST_SRC}
	(cd ${PREFIX}; ${FIND} include/bind -type f -print ) >> ${PLIST_SRC}
	(cd ${PREFIX}; ${FIND} include/bind -type d -print ) | \
		${SED} -e 's/^/@dirrm /' | ${SORT} -r >> ${PLIST_SRC}

.include "../../mk/pthread.buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "none") || \
	!empty(MACHINE_PLATFORM:MNetBSD-*-vax) || \
	!empty(MACHINE_PLATFORM:MNetBSD-*-sparc) || \
	!empty(MACHINE_PLATFORM:MNetBSD-*-sparc64) || \
	!empty(MACHINE_PLATFORM:MNetBSD-*-m68k)
CONFIGURE_ARGS+=	--disable-threads
.else
CONFIGURE_ARGS+=	--enable-threads
.endif
