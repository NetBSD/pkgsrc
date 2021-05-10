# $NetBSD: Makefile,v 1.7 2021/05/10 14:24:47 taca Exp $

COMPAT_PKG=		compat15	# for compat_netbsd/Makefile.common
NETBSD_VERSION=		1.5
PKGREVISION=		2

HOMEPAGE=		https://www.NetBSD.org/releases/formal-1.5/index.html
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
	cd ${WRKSRC}/usr/lib && rm -f libtermlib.so.0.0 && \
		ln -fs libtermcap.so.0.4 libtermlib.so.0.4
.endif

CHECK_RELRO_SKIP+=	*

.include "../../mk/bsd.pkg.mk"
