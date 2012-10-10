# $NetBSD: Makefile,v 1.11.2.1 2012/10/10 13:48:13 tron Exp $

DISTNAME=	bind-${BIND_VERSION}
PKGNAME=	${DISTNAME:S/-P/pl/}
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.isc.org/isc/bind9/${BIND_VERSION}/ \
		http://ftp.belnet.be/pub/mirror/ftp.isc.org/isc/bind9/${BIND_VERSION}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.isc.org/software/bind/
COMMENT=	Version 9.9 of the Berkeley Internet Name Daemon, implementation of DNS

CONFLICTS+=	bind<9.9.0

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=	no

BIND_VERSION=	9.9.2

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

DOCS=			CHANGES FAQ README REDIRECT-NOTES

FILES_SUBST+=		BIND_GROUP=${BIND_GROUP:Q} \
			BIND_USER=${BIND_USER:Q} PAX=${PAX:Q}
MESSAGE_SUBST+=		BIND_DIR=${BIND_DIR} BIND_USER=${BIND_USER}
DOCDIR=			${DESTDIR}${PREFIX}/share/doc/bind9

# include/isc/ipv6.h is installed on non-ipv6 platforms
PLIST_VARS+=	inet6
.if !empty(MISSING_FEATURES:Minet6)
PLIST.inet6=	yes
.endif

RCD_SCRIPTS=		lwresd named9

INSTALLATION_DIRS=	${DOCDIR} share/doc/bind9/arm

post-install:
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/arm/*.html ${DOCDIR}/arm

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
