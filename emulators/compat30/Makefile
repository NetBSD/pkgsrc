# $NetBSD: Makefile,v 1.7 2017/12/24 09:43:56 wiz Exp $

COMPAT_PKG=		compat30	# for compat_netbsd/Makefile.common
NETBSD_VERSION=		3.0

HOMEPAGE=		https://www.netbsd.org/releases/formal-3/
COMMENT=		Shared libraries for NetBSD 3.0 compatibility

.if defined(NETBSD_COMPAT32)
EMUL_PLATFORMS=		netbsd-i386 netbsd-sparc

ACCEPTABLE_NETBSD=	NetBSD-2.99.* NetBSD-3.[0-9]			\
			NetBSD-3.[1-8][0-9]* NetBSD-3.9[0-8]*		\
			NetBSD-3.99.* NetBSD-[4-9]* NetBSD-[1-9][0-9]*
.else
EMUL_PLATFORMS=		netbsd-alpha netbsd-arm netbsd-i386 netbsd-m68k	\
			netbsd-mipseb netbsd-mipsel netbsd-powerpc	\
			netbsd-sh3eb netbsd-sh3el netbsd-sparc		\
			netbsd-sparc64 netbsd-vax netbsd-x86_64

ONLY_FOR_PLATFORM=	NetBSD-3.99.*-* NetBSD-[4-9]*-* NetBSD-[1-9][0-9]*-*
.endif

.include "../../emulators/compat_netbsd/Makefile.common"

DISTNAME=		compat30-${EMUL_ARCH}-${COMPAT_VERSION}
COMPAT_VERSION=		3.1

# For COMPAT_NETBSD32, we need to depend on the compat30-extras package
# on NetBSD-3.0 to supply the missing shared libraries; otherwise, we
# just depend on the compat40 package for the missing shared libraries.
#
.if defined(NETBSD_COMPAT32)
COMPAT_EXTRAS=	# empty
.  for _netbsd_ in ${ACCEPTABLE_NETBSD}
COMPAT_EXTRAS=	netbsd32_compat30-extras-${COMPAT_VERSION}{,nb*}:../../emulators/netbsd32_compat30-extras
.  endfor
.  if !empty(COMPAT_EXTRAS)
DEPENDS+=	${COMPAT_EXTRAS}
.  else
DEPENDS+=	netbsd32_compat40>=4.0:../../emulators/netbsd32_compat40
.  endif
#
# vax running NetBSD-4.x lacks any shared libraries, so depend on the
# compat30-extras package to supply shared libraries missing from compat30.
#
.elif (${EMUL_ARCH} == "vax") && \
      (!empty(OS_VERSION:M3.99.*) || !empty(OS_VERSION:M4.[0-9]) || \
       !empty(OS_VERSION:M4.[1-8][0-9].*) || empty(NetBSD-4.9[0-8].*))
DEPENDS+=	compat30-extras-${COMPAT_VERSION}{,nb*}:../../emulators/compat30-extras
#
# We need to depend on the compat40 package to supply shared libraries
# missing from compat30 on NetBSD>4.x.
#
.elif empty(OS_VERSION:M[0-3].*) && empty(OS_VERSION:M4.[0-9]) && \
      empty(OS_VERSION:M4.[0-9]_STABLE) && \
      empty(OS_VERSION:M4.[0-9].*) && empty(OS_VERSION:M4.[1-8][0-9].*) && \
      empty(OS_VERSION:M4.9[0-8]*)
DEPENDS+=	compat40>=4.0:../../emulators/compat40
.endif

.include "../../mk/bsd.pkg.mk"
