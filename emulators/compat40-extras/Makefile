# $NetBSD: Makefile,v 1.2 2008/01/15 15:43:49 jlam Exp $

COMPAT_PKG=		compat40	# for compat_netbsd/Makefile.common
NETBSD_VERSION=		4.0

HOMEPAGE=		http://www.NetBSD.org/releases/formal-4/index.html
COMMENT=		Additional shared libraries for NetBSD 4.0 compatibility

# XXX Until NetBSD 5.0 is released, we fetch the distfiles into a date-specific
# XXX subdirectory where the date corresponds to the build of HEAD against
# XXX which these compat40 packages were generated.
#
DIST_SUBDIR=		20071230

EMUL_PLATFORMS=		netbsd-i386 netbsd-sparc

.include "../../emulators/compat_netbsd/Makefile.common"

DISTNAME=		compat40-extras-${EMUL_ARCH}-4.0

# This package should only be installed for COMPAT_NETBSD32 emulation
# on machines running NetBSD-4.x.
#
.if defined(NETBSD_COMPAT32)
ACCEPTABLE_NETBSD=	NetBSD-3.99.* NetBSD-4.[0-9]			\
			NetBSD-4.[1-8][0-9].* NetBSD-4.9[0-8].*
.else
NOT_FOR_PLATFORM=	NetBSD-*-${MACHINE_ARCH}
.endif

.include "../../mk/bsd.pkg.mk"
