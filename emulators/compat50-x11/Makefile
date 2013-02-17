# $NetBSD: Makefile,v 1.1 2013/02/17 17:24:08 spz Exp $

COMPAT_PKG=		compat50	# for compat_netbsd/Makefile.common
NETBSD_VERSION=		5.0

HOMEPAGE=		http://www.NetBSD.org/releases/formal-5/index.html
COMMENT=		Shared X11 libraries for NetBSD 5.0 compatibility
LICENSE=		mit

# the other arches didn't have compat-breaking changes in X11
# between 5.0 and 5.1
EMUL_PLATFORMS=		netbsd-i386 netbsd-sparc64 netbsd-x86_64

ONLY_FOR_PLATFORM=	NetBSD-5.[1-9]*-* NetBSD-[6-9]*-* NetBSD-[1-9][0-9]*-*

.include "../../emulators/compat_netbsd/Makefile.common"

DISTNAME=		compat50-x11-${EMUL_ARCH}-${COMPAT_VERSION}
COMPAT_VERSION=		5.0

# pulling in later release compats through the main compat package

.include "../../mk/bsd.pkg.mk"
