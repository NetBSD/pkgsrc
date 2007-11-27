# $NetBSD: Makefile,v 1.4 2007/11/27 19:20:42 jlam Exp $

COMPAT_PKG=		compat15	# for compat_netbsd/Makefile.common
NETBSD_VERSION=		1.5

HOMEPAGE=		http://www.NetBSD.org/releases/formal-1.5/index.html
COMMENT=		Shared libraries for NetBSD 1.5 compatibility

.if defined(NETBSD_COMPAT32)
EMUL_PLATFORMS=		netbsd-i386 netbsd-sparc

ACCEPTABLE_NETBSD=	NetBSD-1.4[A-Z]* NetBSD-1.5 NetBSD-1.5.*	\
			NetBSD-1.5[A-Z]* NetBSD-1.[6-9]* NetBSD-[2-9]*	\
			NetBSD-[1-9][0-9]*
.else
EMUL_PLATFORMS=		netbsd-alpha netbsd-arm netbsd-i386 netbsd-m68k	\
			netbsd-mipsel netbsd-ns32k netbsd-powerpc	\
			netbsd-sparc netbsd-sparc64 netbsd-vax

ONLY_FOR_PLATFORM=	NetBSD-1.5[A-Z]*-* NetBSD-1.[6-9]*-*		\
			NetBSD-[2-9]*-* NetBSD-[1-9][0-9]*-*
NOT_FOR_PLATFORM=	NetBSD-*-x86_64
.endif

.include "../../emulators/compat_netbsd/Makefile.common"

.if (${EMUL_PLATFORM} == "netbsd-sparc64")
DISTNAME=		compat15-${EMUL_ARCH}-1.5.2
.else
DISTNAME=		compat15-${EMUL_ARCH}-${COMPAT_VERSION}
.endif
COMPAT_VERSION=		1.5.3

# For COMPAT_NETBSD32, we need to depend on the compat15-extras package
# on NetBSD-1.5 to supply the missing shared libraries; otherwise, we
# just depend on the compat16 for the missing shared libraries.
#
.if defined(NETBSD_COMPAT32)
COMPAT_EXTRAS=  # empty
.  for _netbsd_ in ${ACCEPTABLE_NETBSD}
COMPAT_EXTRAS=	netbsd32_compat15-extras-${COMPAT_VERSION}{,nb*}:../../emulators/netbsd32_compat15-extras
.  endfor
.  if !empty(COMPAT_EXTRAS)
DEPENDS+=	${COMPAT_EXTRAS}
.  else
DEPENDS+=	netbsd32_compat16>=1.6:../../emulators/netbsd32_compat16
.  endif
#
# arm, m68k and vax switched from a.out to ELF after NetBSD-1.5, and
# they don't need any other packages to supply missing a.out shared
# libraries.
#
.elif (${EMUL_ARCH} == "arm") || (${EMUL_ARCH} == "m68k") || \
      (${EMUL_ARCH} == "vax")
#DEPENDS+=	# no additional dependencies
#
# We need to depend on the compat16 package to supply shared libraries
# missing from compat15 on NetBSD>1.6.
#
.elif empty(OS_VERSION:M0.[0-9]*) && empty(OS_VERSION:M1.[0-5]*) && \
      empty(OS_VERSION:M1.6) && empty(OS_VERSION:M1.6.*)
DEPENDS+=	compat16>=1.6:../../emulators/compat16
.endif

.include "../../mk/bsd.pkg.mk"
