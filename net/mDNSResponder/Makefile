# $NetBSD: Makefile,v 1.21 2006/07/11 14:39:29 drochner Exp $

DISTNAME=	mDNSResponder-108
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://darwinsource.opendarwin.org/tarballs/apsl/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://developer.apple.com/darwin/projects/bonjour/
COMMENT=	Apple's mDNS responder

USE_TOOLS+=	gmake
BUILD_DIRS=	mDNSPosix
BUILDDIR=	${WRKSRC}/mDNSPosix/build/prod

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

BUILD_DEFS+=	USE_INET6
.if defined(USE_INET6) && ${USE_INET6} == "YES"
MAKE_ENV+=	HAVE_IPV6=1
.endif

do-install:
	for i in ${BINARY}; do \
		${INSTALL_PROGRAM} ${BUILDDIR}/$$i ${PREFIX}/bin; \
	done
	for i in ${SBINARY}; do \
		${INSTALL_PROGRAM} ${BUILDDIR}/$$i ${PREFIX}/sbin; \
	done
	${INSTALL_DATA} ${WRKSRC}/mDNSShared/dns_sd.h ${PREFIX}/include
	${INSTALL_LIB} ${BUILDDIR}/libdns_sd.${SO_SUFFIX} ${PREFIX}/lib

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
