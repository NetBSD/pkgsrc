# $NetBSD: Makefile,v 1.39 2015/08/29 17:41:07 jperkin Exp $

DISTNAME=	mDNSResponder-258.14
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.opensource.apple.com/tarballs/mDNSResponder/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://developer.apple.com/bonjour/
COMMENT=	Apple's mDNS responder
LICENSE=	apache-2.0 AND modified-bsd

USE_TOOLS+=		gmake flex bison
BUILD_DIRS=		mDNSPosix
BUILDDIR=		${WRKSRC}/mDNSPosix/build/prod
AUTO_MKDIRS=		yes
MAKE_JOBS_SAFE=		no

USE_GCC_RUNTIME=	yes

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
MAKE_ENV+=	os=x
SO_SUFFIX=	dylib
.else
MAKE_ENV+=	os=netbsd
.endif
PLIST_SUBST+=	SO_SUFFIX=${SO_SUFFIX:Q}

BINARY=		mDNSClientPosix mDNSIdentify mDNSNetMonitor \
		mDNSProxyResponderPosix mDNSResponderPosix
SBINARY=	mdnsd dnsextd

.if !empty(MACHINE_PLATFORM:MNetBSD-3.99.[1-7]-*) || \
    !empty(MACHINE_PLATFORM:MNetBSD-3.[0-9]-*) || \
    !empty(MACHINE_PLATFORM:MNetBSD-3.[0-9][._]*) || \
    !empty(MACHINE_PLATFORM:MNetBSD-[0-2]*) || \
    !empty(MACHINE_PLATFORM:MSunOS-5.[0-9]-*)
.include "../../devel/librfuncs/buildlink3.mk"

MAKE_ENV+=	EXTRA_LIBS=-Wl,-R${BUILDLINK_PREFIX.librfuncs}/lib\ ${BUILDLINK_LDFLAGS.librfuncs:Q}
.else
MAKE_ENV+=	EXTRA_LIBS=
.endif

LDFLAGS.SunOS+=	-lsocket

PKG_OPTIONS_VAR=	PKG_OPTIONS.mDNSResponder
PKG_SUPPORTED_OPTIONS=	inet6
PKG_SUGGESTED_OPTIONS=	inet6

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
	${INSTALL_PROGRAM} ${WRKSRC}/Clients/build/dns-sd ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mDNSShared/dns-sd.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/mDNSShared/dnsextd.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_MAN} ${WRKSRC}/mDNSShared/mDNSResponder.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/mdnsd.8
	${INSTALL_DATA} ${WRKSRC}/mDNSShared/dns_sd.h ${DESTDIR}${PREFIX}/include
	${INSTALL_LIB} ${BUILDDIR}/libdns_sd.${SO_SUFFIX} ${DESTDIR}${PREFIX}/lib

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
