# $NetBSD: Makefile,v 1.3 2007/10/07 12:59:12 kano Exp $

COMPAT_PKG=		compat20	# for compat_netbsd/Makefile.common
NETBSD_VERSION=		2.0

HOMEPAGE=		http://www.NetBSD.org/releases/formal-2.0/index.html
COMMENT=		Additional shared libraries for NetBSD 2.0 compatibility

EMUL_PLATFORMS=		netbsd-i386 netbsd-sparc

.include "../../emulators/compat_netbsd/Makefile.common"

DISTNAME=		compat20-extras-${EMUL_ARCH}-2.1

# This package should only be installed for COMPAT_NETBSD32 emulation
# on machines running NetBSD-2.x.
#
.if defined(NETBSD_COMPAT32)
ACCEPTABLE_NETBSD=	NetBSD-1.6[A-Z]* NetBSD-2.[0-9]			\
			NetBSD-2.[1-8][0-9].* NetBSD-2.9[0-8].*
.else
NOT_FOR_PLATFORM=	NetBSD-*-${MACHINE_ARCH}
.endif

.include "../../mk/bsd.pkg.mk"
