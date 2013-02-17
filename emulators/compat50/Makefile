# $NetBSD: Makefile,v 1.1 2013/02/17 17:24:07 spz Exp $

COMPAT_PKG=		compat50	# for compat_netbsd/Makefile.common
NETBSD_VERSION=		5.0

HOMEPAGE=		http://www.NetBSD.org/releases/formal-5/index.html
COMMENT=		Shared libraries for NetBSD 5.0 compatibility
LICENSE=		modified-bsd

EMUL_PLATFORMS=		netbsd-alpha netbsd-arm netbsd-i386 netbsd-m68k	\
			netbsd-mipseb netbsd-mipsel netbsd-powerpc	\
			netbsd-sparc netbsd-sparc64 netbsd-x86_64

ONLY_FOR_PLATFORM=	NetBSD-5.[1-9]*-* NetBSD-[6-9]*-* NetBSD-[1-9][0-9]*-*

.include "../../emulators/compat_netbsd/Makefile.common"

DISTNAME=		compat50-${EMUL_ARCH}-${COMPAT_VERSION}
COMPAT_VERSION=		5.0

# should we get a 5.10 this rule would need to be amended
.if empty(OS_VERSION:M[0-4].*) && empty(OS_VERSION:M5.[0-9].*)
DEPENDS+=	compat51>=5.1:../../emulators/compat51
.endif

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
