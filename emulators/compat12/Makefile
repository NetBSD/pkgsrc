# $NetBSD: Makefile,v 1.35 2007/10/07 12:59:11 kano Exp $

COMPAT_PKG=		compat12	# for compat_netbsd/Makefile.common
NETBSD_VERSION=		1.2
PKGREVISION=		1

HOMEPAGE=		http://www.NetBSD.org/releases/formal-1.2/index.html
COMMENT=		Shared libraries for NetBSD 1.2 compatibility

EMUL_PLATFORMS=		netbsd-i386 netbsd-m68k netbsd-ns32k netbsd-sparc

ONLY_FOR_PLATFORM=	NetBSD-1.2[A-Z]*-* NetBSD-1.[3-9]*-*		\
			NetBSD-[2-9]*-* NetBSD-[1-9][0-9]*-*

.include "../../emulators/compat_netbsd/Makefile.common"

.if (${EMUL_PLATFORM} == "netbsd-ns32k")
DISTNAME=		compat12-${EMUL_ARCH}-1.2
.else
DISTNAME=		compat12-${EMUL_ARCH}-1.2.1
.endif

# We need to depend on the compat13 package to supply shared libraries
# missing from compat12 on NetBSD>1.3.
#
.if empty(OS_VERSION:M0.[0-9]*) && empty(OS_VERSION:M1.[0-2]*) && \
    empty(OS_VERSION:M1.3) && empty(OS_VERSION:M1.3.*)
DEPENDS+=		compat13>=1.3:../../emulators/compat13
.endif

.include "../../mk/bsd.pkg.mk"
