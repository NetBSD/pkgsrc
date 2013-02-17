# $NetBSD: Makefile,v 1.1 2013/02/17 17:24:09 spz Exp $

COMPAT_PKG=		compat51	# for compat_netbsd/Makefile.common
NETBSD_VERSION=		5.1

HOMEPAGE=		http://www.NetBSD.org/releases/formal-5/index.html
COMMENT=		Shared X11 libraries for NetBSD 5.1 compatibility
LICENSE=		mit

EMUL_PLATFORMS=		netbsd-alpha netbsd-arm netbsd-i386 netbsd-m68k	\
			netbsd-mipseb netbsd-mipsel netbsd-powerpc	\
			netbsd-sparc netbsd-sparc64 netbsd-x86_64

ONLY_FOR_PLATFORM=	NetBSD-5.[3-9]-* NetBSD-[6-9]*-* NetBSD-[1-9][0-9]*-*

.include "../../emulators/compat_netbsd/Makefile.common"

DISTNAME=		compat51-x11-${EMUL_ARCH}-${COMPAT_VERSION}
COMPAT_VERSION=		5.1

# pulling in later release compats through the main compat package

.include "../../mk/bsd.pkg.mk"
