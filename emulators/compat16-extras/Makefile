# $NetBSD: Makefile,v 1.3 2007/10/07 12:59:12 kano Exp $

COMPAT_PKG=		compat16	# for compat_netbsd/Makefile.common
NETBSD_VERSION=		1.6

HOMEPAGE=		http://www.NetBSD.org/releases/formal-1.6/index.html
COMMENT=		Additional shared libraries for NetBSD 1.6 compatibility

EMUL_PLATFORMS=		netbsd-i386 netbsd-sparc

.include "../../emulators/compat_netbsd/Makefile.common"

DISTNAME=		compat16-extras-${EMUL_ARCH}-1.6.2

# This package should only be installed for COMPAT_NETBSD32 emulation
# on machines running NetBSD-1.6.
#
.if defined(NETBSD_COMPAT32)
ACCEPTABLE_NETBSD=	NetBSD-1.5[A-Z]* NetBSD-1.6 NetBSD-1.6.*
.else
NOT_FOR_PLATFORM=	NetBSD-*-${MACHINE_ARCH}
.endif

.include "../../mk/bsd.pkg.mk"
