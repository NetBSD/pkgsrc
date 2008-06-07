# $NetBSD: Makefile,v 1.4 2008/06/07 21:20:46 joerg Exp $

COMPAT_PKG=		compat15	# for compat_netbsd/Makefile.common
NETBSD_VERSION=		1.5
PKGREVISION=		1

HOMEPAGE=		http://www.NetBSD.org/releases/formal-1.5/index.html
COMMENT=		Additional shared libraries for NetBSD 1.5 compatibility

EMUL_PLATFORMS=		netbsd-i386 netbsd-sparc

.include "../../emulators/compat_netbsd/Makefile.common"

DISTNAME=		compat15-extras-${EMUL_ARCH}-1.5.3

# This package should only be installed for COMPAT_NETBSD32 emulation
# on machines running NetBSD-1.5.
#
.if defined(NETBSD_COMPAT32)
ACCEPTABLE_NETBSD=	NetBSD-1.4[A-Z]* NetBSD-1.5 NetBSD-1.5.*
.else
NOT_FOR_PLATFORM=	NetBSD-*-${MACHINE_ARCH}
.endif

.if ${EMUL_ARCH} == "i386"
post-extract:
	cd ${WRKSRC}/usr/lib && mv libtermlib.so.0.0 libtermlib.so.0.4
.endif

.include "../../mk/bsd.pkg.mk"
