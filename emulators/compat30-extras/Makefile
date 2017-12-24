# $NetBSD: Makefile,v 1.5 2017/12/24 09:44:16 wiz Exp $

COMPAT_PKG=		compat30	# for compat_netbsd/Makefile.common
NETBSD_VERSION=		3.0

HOMEPAGE=		https://www.netbsd.org/releases/formal-3/
COMMENT=		Additional shared libraries for NetBSD 3.0 compatibility

EMUL_PLATFORMS=		netbsd-i386 netbsd-sparc netbsd-vax

.include "../../emulators/compat_netbsd/Makefile.common"

DISTNAME=		compat30-extras-${EMUL_ARCH}-3.1

# This package should only be installed for COMPAT_NETBSD32 emulation
# on machines running NetBSD-3.x, or on vax running NetBSD-4.x which
# lacks any shared libraries.
#
.if defined(NETBSD_COMPAT32)
ACCEPTABLE_NETBSD=	NetBSD-2.99.* NetBSD-3.[0-9]			\
			NetBSD-3.[1-8][0-9].* NetBSD-3.9[0-8].*
.else
ACCEPTABLE_NETBSD=	NetBSD-3.99.* NetBSD-4.[0-9]			\
			NetBSD-4.[1-8][0-9].* NetBSD-4.9[0-8].*
ONLY_FOR_PLATFORM=	${ACCEPTABLE_NETBSD:S/$/-vax/}
.endif

.include "../../mk/bsd.pkg.mk"
