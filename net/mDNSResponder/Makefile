# $NetBSD: Makefile,v 1.47 2024/11/25 12:13:00 hauke Exp $

DISTNAME=	${GITHUB_PROJECT}-${PKGVER}
GITHUB_PROJECT=	mDNSResponder
PKGVER=		2559.1.1
GITHUB_TAG=	refs/tags/${GITHUB_PROJECT}-${PKGVER}
MASTER_SITES=	${MASTER_SITE_GITHUB:=apple-oss-distributions/}

CATEGORIES=	net

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://developer.apple.com/bonjour/
COMMENT=	Apple's mDNS responder
LICENSE=	apache-2.0 AND modified-bsd

USE_LANGUAGES=	c c++

USE_TOOLS+=		gmake flex bison

MAKE_JOBS_SAFE=		no

WRKSRC=			${WRKDIR}/mDNSResponder-mDNSResponder-2559.1.1
BUILD_DIRS=		mDNSPosix
BUILDDIR=		${WRKSRC}/mDNSPosix/build/prod

CFLAGS+=		-Wno-missing-braces
CFLAGS+=		-DPID_FILE=\"${VARBASE}/run/mdnsd/mdnsd.pid\"
CFLAGS+=		-DMDNS_UDS_SERVERPATH=\"${VARBASE}/run/mdnsd/mdnsd\"

USE_GCC_RUNTIME=	yes

# File names with spaces
CHECK_PORTABILITY_SKIP+=	mDNSMacOSX/*

CHECK_RELRO_SKIP+=	lib/libdns_sd.${SO_SUFFIX}

MAKE_ENV.NetBSD+=	os=netbsd
MAKE_ENV.FreeBSD+=	os=freebsd
MAKE_ENV.OpenBSD+=	os=openbsd
MAKE_ENV.SunOS+=	os=solaris
MAKE_ENV.Linux+=	os=linux tls=no
MAKE_ENV.Darwin+=	os=x
MAKE_ENV.*+=		os=netbsd

OPSYSVARS+=		SO_SUFFIX
SO_SUFFIX.Darwin=	dylib
SO_SUFFIX.*=		so
PLIST_SUBST+=		SO_SUFFIX=${SO_SUFFIX:Q}

BINARY=			mDNSClientPosix mDNSNetMonitor \
			mDNSProxyResponderPosix mDNSResponderPosix

SBINARY=		mdnsd

BUILD_DEFS+=		VARBASE

RCD_SCRIPTS=		mdnsd

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MSunOS-5.[0-9]-*)
.include "../../devel/librfuncs/buildlink3.mk"

MAKE_ENV+=	EXTRA_LIBS=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.librfuncs}/lib\ ${BUILDLINK_LDFLAGS.librfuncs:Q}
.else
MAKE_ENV+=	EXTRA_LIBS=
.endif

LDFLAGS.SunOS+=	-lsocket

PKG_OPTIONS_VAR=	PKG_OPTIONS.mDNSResponder
PKG_SUPPORTED_OPTIONS=	inet6
PKG_SUGGESTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

MDNS_USER?=		_mdnsd
MDNS_GROUP?=		_mdnsd

PKG_USERS_VARS+=	MDNS_USER
PKG_GROUPS_VARS+=	MDNS_GROUP
PKG_GROUPS=		${MDNS_GROUP}
PKG_USERS=		${MDNS_USER}:${MDNS_GROUP}

PKG_GECOS.${MDNS_USER}=	MDNS web server user
PKG_HOME.${MDNS_USER}=	/nonexistent
PKG_SHELL.${MDNS_USER}=	${NOLOGIN}

FILES_SUBST+=		MDNS_USER=${MDNS_USER}
FILES_SUBST+=		MDNS_GROUP=${MDNS_GROUP}

SUBST_CLASSES+=		user
SUBST_STAGE.user=	pre-configure
SUBST_MESSAGE.user=	Fixing unprivileged user name.
SUBST_FILES.user=	mDNSPosix/PosixDaemon.c
SUBST_SED.user=		-e 's,nobody,${MDNS_USER},g'

.if !empty(PKG_OPTIONS:Minet6)
MAKE_ENV+=	HAVE_IPV6=1
.endif

INSTALLATION_DIRS=	bin sbin lib include
INSTALLATION_DIRS+=	${PKGMANDIR}/man1 ${PKGMANDIR}/man8

do-install:
	for i in ${BINARY}; do \
		${INSTALL_PROGRAM} ${BUILDDIR}/$$i ${DESTDIR}${PREFIX}/bin; \
	done
	for i in ${SBINARY}; do \
		${INSTALL_PROGRAM} ${BUILDDIR}/$$i ${DESTDIR}${PREFIX}/sbin; \
	done
	${INSTALL_PROGRAM} ${WRKSRC}/Clients/build/dns-sd ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mDNSShared/dns-sd.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/mDNSShared/mDNSResponder.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/mdnsd.8
	${INSTALL_DATA} ${WRKSRC}/mDNSShared/dns_sd.h ${DESTDIR}${PREFIX}/include
	${INSTALL_LIB} ${BUILDDIR}/libdns_sd.${SO_SUFFIX} ${DESTDIR}${PREFIX}/lib

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
