# $NetBSD: Makefile,v 1.24 2007/12/21 11:59:39 obache Exp $

DISTNAME=	mDNSResponder-108
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://darwinsource.opendarwin.org/tarballs/apsl/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://developer.apple.com/opensource/internet/bonjour.html
COMMENT=	Apple's mDNS responder

USE_TOOLS+=	gmake
BUILD_DIRS=	mDNSPosix
BUILDDIR=	${WRKSRC}/mDNSPosix/build/prod

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

SO_SUFFIX=	so
.if ${OPSYS} == "NetBSD"
MAKE_ENV+=	os=netbsd
.elif ${OPSYS} == "FreeBSD"
MAKE_ENV+=	os=freebsd
.elif ${OPSYS} == "OpenBSD"
MAKE_ENV+=	os=openbsd
.elif ${OPSYS} == "SunOS"
MAKE_ENV+=	os=solaris
.elif ${OPSYS} == "Linux"
MAKE_ENV+=	os=linux
.elif ${OPSYS} == "Darwin"
.  if !empty(OS_VERSION:M6*)
MAKE_ENV+=	os=jaguar
.  elif !empty(OS_VERSION:M7*)
MAKE_ENV+=	os=panther
.  elif !empty(OS_VERSION:M8*)
MAKE_ENV+=	os=tiger
.  endif
SO_SUFFIX=	dylib
.else
MAKE_ENV+=	os=netbsd
.endif
PLIST_SUBST+=	SO_SUFFIX=${SO_SUFFIX:Q}

BINARY=		mDNSClientPosix mDNSIdentify mDNSNetMonitor \
		mDNSProxyResponderPosix mDNSResponderPosix
SBINARY=	mdnsd dnsextd

INSTALLATION_DIRS=	bin include lib sbin

.if !empty(MACHINE_PLATFORM:MNetBSD-3.99.[1-7]-*) || \
    !empty(MACHINE_PLATFORM:MNetBSD-3.[0-9]-*) || \
    !empty(MACHINE_PLATFORM:MNetBSD-3.[0-9][._]*) || \
    !empty(MACHINE_PLATFORM:MNetBSD-[0-2]*) || \
    !empty(MACHINE_PLATFORM:MSunOS-5.[0-9]-*)
.include "../../devel/librfuncs/buildlink3.mk"

MAKE_ENV+=	EXTRA_LIBS=-Wl,-R${BUILDLINK_PREFIX.librfuncs:Q}/lib\ ${BUILDLINK_LDFLAGS.librfuncs:Q}
.else
MAKE_ENV+=	EXTRA_LIBS=
.endif

PKG_OPTIONS_VAR=	PKG_OPTIONS.mDNSResponder
PKG_SUPPORTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
MAKE_ENV+=	HAVE_IPV6=1
.endif

do-install:
	for i in ${BINARY}; do \
		${INSTALL_PROGRAM} ${BUILDDIR}/$$i ${DESTDIR}${PREFIX}/bin; \
	done
	for i in ${SBINARY}; do \
		${INSTALL_PROGRAM} ${BUILDDIR}/$$i ${DESTDIR}${PREFIX}/sbin; \
	done
	${INSTALL_DATA} ${WRKSRC}/mDNSShared/dns_sd.h ${DESTDIR}${PREFIX}/include
	${INSTALL_LIB} ${BUILDDIR}/libdns_sd.${SO_SUFFIX} ${DESTDIR}${PREFIX}/lib

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
