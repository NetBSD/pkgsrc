# $NetBSD: Makefile,v 1.16 2012/09/13 01:35:18 taca Exp $

DISTNAME=	bind-${BIND_VERSION}
PKGNAME=	${DISTNAME:S/-P/pl/}
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.isc.org/isc/bind9/${BIND_VERSION}/ \
		http://ftp.belnet.be/pub/mirror/ftp.isc.org/isc/bind9/${BIND_VERSION}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.isc.org/software/bind/
COMMENT=	Version 9.8 of the Berkeley Internet Name Daemon, implementation of DNS

CONFLICTS+=	bind<9.8.0

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=	no

BIND_VERSION=	9.8.3-P3

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	BIND_DIR VARBASE

.include "options.mk"

USE_TOOLS+=		pax perl
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
#CONFIG_SHELL=		sh -x

CONFIGURE_ARGS+=	--with-libtool
CONFIGURE_ARGS+=	--sysconfdir=/etc
CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
CONFIGURE_ARGS+=	--disable-openssl-version-check
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE:Q}
.if ${MACHINE_PLATFORM:MNetBSD-*-mipsel} != ""
CONFIGURE_ARGS+=        --disable-atomic
.endif
.if ${MACHINE_PLATFORM:MNetBSD-*-powerpc} != ""
CONFIGURE_ARGS+=	--disable-threads
.endif
.if ${OPSYS} == "DragonFly"
CONFIGURE_ARGS+=       --disable-kqueue
.endif

PKG_GROUPS_VARS+=	BIND_GROUP
PKG_USERS_VARS+=	BIND_USER

PKG_GROUPS=		${BIND_GROUP}
PKG_USERS=		${BIND_USER}:${BIND_GROUP}

PKG_GECOS.${BIND_USER}=	Named pseudo-user
PKG_HOME.${BIND_USER}=	${BIND_DIR}

PTHREAD_OPTS+=		native
PTHREAD_AUTO_VARS=	yes

FILES_SUBST+=		BIND_GROUP=${BIND_GROUP:Q} \
			BIND_USER=${BIND_USER:Q} PAX=${PAX:Q}
MESSAGE_SUBST+=		BIND_DIR=${BIND_DIR} BIND_USER=${BIND_USER}
DOCDIR=			${DESTDIR}${PREFIX}/share/doc/bind9
MISCDOC=		dnssec ipv6 migration migration-4to9 options \
			rfc-compliance roadmap sdb

# include/isc/ipv6.h is installed on non-ipv6 platforms
PLIST_VARS+=	inet6
.if !empty(MISSING_FEATURES:Minet6)
PLIST.inet6=	yes
.endif

RCD_SCRIPTS=		lwresd named9

INSTALLATION_DIRS=	${DOCDIR} share/doc/bind9/arm share/doc/bind9/misc

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/arm/*.html ${DOCDIR}/arm
	cd ${WRKSRC}/doc/misc && ${INSTALL_DATA} ${MISCDOC} ${DOCDIR}/misc

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
