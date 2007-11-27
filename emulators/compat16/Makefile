# $NetBSD: Makefile,v 1.14 2007/11/27 19:20:42 jlam Exp $

COMPAT_PKG=		compat16	# for compat_netbsd/Makefile.common
NETBSD_VERSION=		1.6

HOMEPAGE=		http://www.NetBSD.org/releases/formal-1.6/index.html
COMMENT=		Shared libraries for NetBSD 1.6 compatibility

.if defined(NETBSD_COMPAT32)
EMUL_PLATFORMS=		netbsd-i386 netbsd-sparc

ACCEPTABLE_NETBSD=	NetBSD-1.5[A-Z]* NetBSD-1.6 NetBSD-1.6.*	\
			NetBSD-1.6[A-Z]* NetBSD-[2-9]*			\
			NetBSD-[1-9][0-9]*
.else
EMUL_PLATFORMS=		netbsd-alpha netbsd-arm netbsd-i386 netbsd-m68k	\
			netbsd-mipseb netbsd-mipsel netbsd-powerpc	\
			netbsd-sparc netbsd-sparc64 netbsd-vax

ONLY_FOR_PLATFORM=	NetBSD-1.6[A-Z]*-* NetBSD-[2-9]*-*		\
			NetBSD-[1-9][0-9]*-*
NOT_FOR_PLATFORM=	NetBSD-*-x86_64
.endif

.include "../../emulators/compat_netbsd/Makefile.common"

DISTNAME=		compat16-${EMUL_ARCH}-${COMPAT_VERSION}
COMPAT_VERSION=		1.6.2

# For COMPAT_NETBSD32, we need to depend on the compat16-extras package
# on NetBSD-1.6 to supply the missing shared libraries; otherwise, we
# just depend on the compat20 package for the missing shared libraries.
#
.if defined(NETBSD_COMPAT32)
COMPAT_EXTRAS=	# empty
.  for _netbsd_ in ${ACCEPTABLE_NETBSD}
COMPAT_EXTRAS=	netbsd32_compat16-extras-${COMPAT_VERSION}{,nb*}:../../emulators/netbsd32_compat16-extras
.  endfor
.  if !empty(COMPAT_EXTRAS)
DEPENDS+=	${COMPAT_EXTRAS}
.  else
DEPENDS+=	netbsd32_compat20>=2.0:../../emulators/netbsd32_compat20
.  endif
#
# We need to depend on the compat20 package to supply shared libraries
# missing from compat16 on NetBSD>2.x.
#
.elif empty(OS_VERSION:M[0-1].*) && empty(OS_VERSION:M2.[0-9]) && \
      empty(OS_VERSION:M2.[0-9].*) && empty(OS_VERSION:M2.[1-8][0-9].*) && \
      empty(OS_VERSION:M2.9[0-8]*)
DEPENDS+=	compat20>=2.0:../../emulators/compat20
.endif

.include "../../mk/bsd.pkg.mk"
