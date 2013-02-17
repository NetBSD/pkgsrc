# $NetBSD: Makefile,v 1.1 2013/02/17 17:24:08 spz Exp $

COMPAT_PKG=		compat51	# for compat_netbsd/Makefile.common
NETBSD_VERSION=		5.1

HOMEPAGE=		http://www.NetBSD.org/releases/formal-5/index.html
COMMENT=		Shared libraries for NetBSD 5.1 compatibility
LICENSE=		2-clause-bsd AND modified-bsd AND isc

EMUL_PLATFORMS=		netbsd-alpha netbsd-arm netbsd-i386 netbsd-m68k	\
			netbsd-mipseb netbsd-mipsel netbsd-powerpc	\
			netbsd-sparc netbsd-sparc64 netbsd-x86_64

ONLY_FOR_PLATFORM=	NetBSD-5.[3-9]*-* NetBSD-[6-9]*-* NetBSD-[1-9][0-9]*-*

.include "../../emulators/compat_netbsd/Makefile.common"

DISTNAME=		compat51-${EMUL_ARCH}-${COMPAT_VERSION}
COMPAT_VERSION=		5.1

# should we get a 5.10 this rule would need to be amended
.if empty(OS_VERSION:M[0-4].*) && empty(OS_VERSION:M5.[3-9].*)
DEPENDS+=	compat60>=6.0:../../emulators/compat60
.endif

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
