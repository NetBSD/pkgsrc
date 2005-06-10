# $NetBSD: Makefile,v 1.4 2005/06/10 23:01:39 markd Exp $

DISTNAME=	mDNSResponder-107.1
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://darwinsource.opendarwin.org/tarballs/apsl/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://developer.apple.com/darwin/projects/bonjour/
COMMENT=	Apple's mDNS responder

USE_TOOLS=	gmake
WRKSRC=		${WRKDIR}/${DISTNAME}/mDNSPosix
BUILDDIR=	${WRKSRC}/build/prod

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
MAKE_ENV+=	os=jaguar
SO_SUFFIX=	dylib
.else
MAKE_ENV+=	os=netbsd
.endif
PLIST_SUBST+=	SO_SUFFIX=${SO_SUFFIX}

BINARY=		mDNSClientPosix mDNSIdentify mDNSNetMonitor \
		mDNSProxyResponderPosix mDNSResponderPosix
SBINARY=	mdnsd dnsextd

do-install:
	for i in ${BINARY}; do \
		${INSTALL_PROGRAM} ${BUILDDIR}/$$i ${PREFIX}/bin; \
	done
	for i in ${SBINARY}; do \
		${INSTALL_PROGRAM} ${BUILDDIR}/$$i ${PREFIX}/sbin; \
	done
	${INSTALL_DATA} ${WRKSRC}/../mDNSShared/dns_sd.h ${PREFIX}/include
	${INSTALL_LIB} ${BUILDDIR}/libdns_sd.${SO_SUFFIX} ${PREFIX}/lib

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
