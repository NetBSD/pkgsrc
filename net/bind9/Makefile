# $NetBSD: Makefile,v 1.110.2.2 2010/02/01 15:00:11 spz Exp $

DISTNAME=	bind-${BIND_VERSION}
PKGNAME=	${DISTNAME:S/-P/pl/}
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.isc.org/isc/bind9/${BIND_VERSION}/ \
		http://ftp.belnet.be/pub/mirror/ftp.isc.org/isc/bind9/${BIND_VERSION}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.isc.org/software/bind
COMMENT=	Version 9 of the Berkeley Internet Name Daemon, implementation of DNS

CONFLICTS+=	bind<9.4.0
CONFLICTS+=	bind>=9.5.0

PKG_DESTDIR_SUPPORT=	user-destdir

BIND_VERSION=	9.4.3-P5

# IPv6 ready, automatically detected
.include "../../mk/bsd.prefs.mk"
BUILD_DEFS+=	IPV6_READY

BUILD_DEFS+=	BIND_DIR VARBASE

USE_TOOLS+=	pax
USE_LIBTOOL=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-libtool=yes \
		--sysconfdir=/etc \
		--localstatedir=${VARBASE:Q}
#LDFLAGS+=	${COMPILER_RPATH_FLAG}${LOCALBASE}/pthreads/lib -L${LOCALBASE}/pthreads/lib
# use external OpenSSL.  comment out the following line and the buildlink
# include at the bottom to use OpenSSL shipped with BIND9.
CONFIGURE_ARGS+=--with-openssl=${SSLBASE:Q}

PKG_GROUPS_VARS+=	BIND_GROUP
PKG_USERS_VARS+=	BIND_USER

PKG_GROUPS=	${BIND_GROUP}
PKG_USERS=	${BIND_USER}:${BIND_GROUP}

PKG_GECOS.${BIND_USER}=	Named pseudo-user
PKG_HOME.${BIND_USER}=	${BIND_DIR}

PTHREAD_OPTS+=	native
PTHREAD_AUTO_VARS=	yes

FILES_SUBST+=	BIND_GROUP=${BIND_GROUP:Q} BIND_USER=${BIND_USER:Q} PAX=${PAX:Q}
MESSAGE_SUBST+=	BIND_DIR=${BIND_DIR} BIND_USER=${BIND_USER}

# include/isc/ipv6.h is installed on non-ipv6 platforms
PLIST_VARS+=	inet6
.if !empty(MISSING_FEATURES:Minet6)
PLIST.inet6=	yes
.endif

PLIST_SRC=	${WRKDIR}/PLIST
RCD_SCRIPTS=	lwresd named9

INSTALLATION_DIRS=	share/doc/bind9/arm share/doc/bind9/draft \
			share/doc/bind9/misc share/doc/bind9/rfc

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/bind9
	set -e; cd ${WRKSRC}/doc && pax -rwppm			\
	  -s ',.*xsl.*,,' -s ',Makefile.*,,' -s ',.*\.pl,,'		\
	  . ${DESTDIR}${PREFIX}/share/doc/bind9
	${CHMOD} -R g-w ${DESTDIR}${PREFIX}/share/doc/bind9
	${CHMOD} -x ${DESTDIR}${PREFIX}/share/doc/bind9/arm/Bv9ARM.pdf
	${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	(cd ${DESTDIR}${PREFIX}; ${FIND} share/doc/bind9 -type f -print ) >> ${PLIST_SRC}
	(cd ${DESTDIR}${PREFIX}; ${FIND} include/bind -type f -print ) >> ${PLIST_SRC}

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
