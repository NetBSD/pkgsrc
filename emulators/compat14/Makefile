# $NetBSD: Makefile,v 1.23 2007/10/07 12:59:11 kano Exp $

COMPAT_PKG=		compat14	# for compat_netbsd/Makefile.common
NETBSD_VERSION=		1.4
PKGREVISION=		2

CONFLICTS=		compat14-crypto-[0-9]*

HOMEPAGE=		http://www.NetBSD.org/releases/formal-1.4/index.html
COMMENT=		Shared libraries for NetBSD 1.4 compatibility

EMUL_PLATFORMS=		netbsd-alpha netbsd-arm netbsd-i386 netbsd-m68k	\
			netbsd-mipsel netbsd-ns32k netbsd-powerpc	\
			netbsd-sparc netbsd-vax

ONLY_FOR_PLATFORM=	NetBSD-1.4[A-Z]*-* NetBSD-1.[5-9]*-*		\
			NetBSD-[2-9]*-* NetBSD-[1-9][0-9]*-*

.include "../../emulators/compat_netbsd/Makefile.common"

.if (${EMUL_PLATFORM} == "netbsd-ns32k")
DISTNAME=		compat14-${EMUL_ARCH}-1.4.2
.elif (${EMUL_PLATFORM} == "netbsd-i386") || \
      (${EMUL_PLATFORM} == "netbsd-sparc")
DISTNAME=		compat14-${EMUL_ARCH}-1.4.3.1
.else
DISTNAME=		compat14-${EMUL_ARCH}-1.4.3
.endif

# For COMPAT_NETBSD32, we need to depend on the compat15 package to supply
# /usr/libexec/ld.so (either directly or indirectly) so that the a.out
# shared libraries can be used.
#
.if ((${EMUL_ARCH} == "i386") && (${MACHINE_ARCH} == "x86_64")) || \
    ((${EMUL_ARCH} == "sparc") && (${MACHINE_ARCH} == "sparc64"))
DEPENDS+=	netbsd32_compat15>=1.5:../../emulators/netbsd32_compat15

# i386 and sparc switched from a.out to ELF after NetBSD-1.4, and
# they don't need any other packages to supply missing a.out shared
# libraries.
#
.elif (${EMUL_ARCH} == "i386") || (${EMUL_ARCH} == "sparc")
#DEPENDS+=	# no additional dependencies
#
# We need to depend on the compat15 package to supply shared libraries
# missing from compat14 on NetBSD>1.5.
#
.elif empty(OS_VERSION:M0.[0-9]*) && empty(OS_VERSION:M1.[0-4]*) && \
      empty(OS_VERSION:M1.5) && empty(OS_VERSION:M1.5.*)
DEPENDS+=	compat15>=1.5:../../emulators/compat15
.endif

.include "../../mk/bsd.pkg.mk"
