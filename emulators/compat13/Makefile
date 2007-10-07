# $NetBSD: Makefile,v 1.31 2007/10/07 12:59:11 kano Exp $

COMPAT_PKG=		compat13	# for compat_netbsd/Makefile.common
NETBSD_VERSION=		1.3
PKGREVISION=		3

HOMEPAGE=		http://www.NetBSD.org/releases/formal-1.3/index.html
COMMENT=		Shared libraries for NetBSD 1.3 compatibility

EMUL_PLATFORMS=		netbsd-alpha netbsd-arm netbsd-i386 netbsd-m68k	\
			netbsd-mipsel netbsd-ns32k netbsd-sparc

ONLY_FOR_PLATFORM=	NetBSD-1.3[A-Z]*-* NetBSD-1.[4-9]*-*		\
			NetBSD-[2-9]*-* NetBSD-[1-9][0-9]*-*

.include "../../emulators/compat_netbsd/Makefile.common"

.if (${EMUL_PLATFORM} == "netbsd-arm")
DISTNAME=		compat13-${EMUL_ARCH}-1.3.2
.else
DISTNAME=		compat13-${EMUL_ARCH}-1.3.3
.endif

# We need to depend on the compat14 package to supply shared libraries
# missing from compat13 on NetBSD>1.4.
#
.if empty(OS_VERSION:M0.[0-9]*) && empty(OS_VERSION:M1.[0-3]*) && \
    empty(OS_VERSION:M1.4) && empty(OS_VERSION:M1.4.*)
DEPENDS+=		compat14>=1.4:../../emulators/compat14
.endif

.include "../../mk/bsd.pkg.mk"
