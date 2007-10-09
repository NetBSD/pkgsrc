# $NetBSD: Makefile,v 1.4 2007/10/09 19:19:09 martti Exp $

COMPAT_PKG=		compat20	# for compat_netbsd/Makefile.common
NETBSD_VERSION=		2.0

HOMEPAGE=		http://www.NetBSD.org/releases/formal-2.0/index.html
COMMENT=		Shared libraries for NetBSD 2.0 compatibility

.if defined(NETBSD_COMPAT32)
EMUL_PLATFORMS=		netbsd-i386 netbsd-sparc

ACCEPTABLE_NETBSD=	NetBSD-1.6[A-Z]* NetBSD-2.[0-9]			\
			NetBSD-2.[1-8][0-9]* NetBSD-2.9[0-8]*		\
			NetBSD-2.99.* NetBSD-[3-9]* NetBSD-[1-9][0-9]*
.else
EMUL_PLATFORMS=		netbsd-alpha netbsd-arm netbsd-i386 netbsd-m68k	\
			netbsd-mipseb netbsd-mipsel netbsd-powerpc	\
			netbsd-sh3eb netbsd-sh3el netbsd-sparc		\
			netbsd-sparc64 netbsd-vax netbsd-x86_64

ONLY_FOR_PLATFORM=	NetBSD-2.99.*-* NetBSD-[3-9]*-*	NetBSD-[1-9][0-9]*-*
.endif

.include "../../emulators/compat_netbsd/Makefile.common"

DISTNAME=		compat20-${EMUL_ARCH}-${COMPAT_VERSION}
COMPAT_VERSION=		2.1

# For COMPAT_NETBSD32, we need to depend on the compat20-extras package
# on NetBSD-2.0 to supply the missing shared libraries; otherwise, we
# just depend on the compat30 package for the missing shared libraries.
#
.if defined(NETBSD_COMPAT32)
COMPAT_EXTRAS=	# empty
.  for _netbsd_ in ${ACCEPTABLE_NETBSD}
COMPAT_EXTRAS=	netbsd32_compat20-extras-${COMPAT_VERSION}{,nb*}:../../emulators/netbsd32_compat20-extras
.  endfor
.  if !empty(COMPAT_EXTRAS)
DEPENDS+=	${COMPAT_EXTRAS}
.  else
DEPENDS+=	netbsd32_compat30>=3.0:../../emulators/netbsd32_compat30
.  endif
#
# We need to depend on the compat30 package to supply shared libraries
# missing from compat20 on NetBSD>3.x.
#
.elif empty(OS_VERSION:M[0-2].*) && empty(OS_VERSION:M3.[0-9]) && \
      empty(OS_VERSION:M3.[0-9].*) && empty(OS_VERSION:M3.[1-8][0-9].*) && \
      empty(OS_VERSION:M3.9[0-8]*)
DEPENDS+=	compat30>=3.0:../../emulators/compat30
.endif

.include "../../mk/bsd.pkg.mk"
