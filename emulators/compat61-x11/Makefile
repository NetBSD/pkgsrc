# $NetBSD: Makefile,v 1.1 2015/05/03 15:01:12 spz Exp $

COMPAT_PKG=		compat61	# for compat_netbsd/Makefile.common
NETBSD_VERSION=		6.1

HOMEPAGE=		http://www.NetBSD.org/releases/formal-6/index.html
COMMENT=		Shared X11 libraries for NetBSD 6.1 compatibility
LICENSE=		mit

EMUL_PLATFORMS=		netbsd-alpha netbsd-arm netbsd-i386 netbsd-m68k	\
			netbsd-mipseb netbsd-mipsel \
			netbsd-mips64eb netbsd-mips64el \
			netbsd-powerpc	\
			netbsd-sparc netbsd-sparc64 netbsd-x86_64

ONLY_FOR_PLATFORM=	NetBSD-[7-9]*-* NetBSD-[1-9][0-9]*-*

.include "../../emulators/compat_netbsd/Makefile.common"

DISTNAME=		compat61-x11-${EMUL_ARCH}-${COMPAT_VERSION}
COMPAT_VERSION=		6.1
DIST_SUBDIR=		20150430

# in this package we want the PLIST.alpha and PLIST.m68k to replace, not
# amend, the common PLIST
.if exists(${PKGDIR}/PLIST.${EMUL_ARCH})
PLIST_SRC=		${PKGDIR}/PLIST.${EMUL_ARCH}
.endif

# pulling in later release compats through the main compat package

.include "../../mk/bsd.pkg.mk"
