# $NetBSD: Makefile,v 1.2 2008/01/15 15:43:48 jlam Exp $

COMPAT_PKG=		compat40	# for compat_netbsd/Makefile.common
NETBSD_VERSION=		4.0

HOMEPAGE=		http://www.NetBSD.org/releases/formal-4/index.html
COMMENT=		Shared libraries for NetBSD 4.0 compatibility

# XXX Until NetBSD 5.0 is released, we fetch the distfiles into a date-specific
# XXX subdirectory where the date corresponds to the build of HEAD against
# XXX which these compat40 packages were generated.
#
DIST_SUBDIR=		20071230

.if defined(NETBSD_COMPAT32)
EMUL_PLATFORMS=		netbsd-i386 netbsd-sparc

ACCEPTABLE_NETBSD=	NetBSD-3.99.* NetBSD-4.[0-9]			\
			NetBSD-4.[1-8][0-9]* NetBSD-4.9[0-8]*		\
			NetBSD-4.99.* NetBSD-[5-9]* NetBSD-[1-9][0-9]*
.else
EMUL_PLATFORMS=		netbsd-alpha netbsd-arm netbsd-i386 netbsd-m68k	\
			netbsd-mipseb netbsd-mipsel netbsd-powerpc	\
			netbsd-sh3eb netbsd-sh3el netbsd-sparc		\
			netbsd-sparc64 netbsd-x86_64

# XXX These platforms are currently not supported or broken.
#EMUL_PLATFORMS=	netbsd-vax

ONLY_FOR_PLATFORM=	NetBSD-4.99.*-* NetBSD-[5-9]*-* NetBSD-[1-9][0-9]*-*
.endif

.include "../../emulators/compat_netbsd/Makefile.common"

DISTNAME=		compat40-${EMUL_ARCH}-${COMPAT_VERSION}
COMPAT_VERSION=		4.0

# For COMPAT_NETBSD32, we need to depend on the compat40-extras package
# on NetBSD-4.0 to supply the missing shared libraries; otherwise, we
# just depend on the compat50 package for the missing shared libraries.
#
.if defined(NETBSD_COMPAT32)
COMPAT_EXTRAS=	# empty
.  for _netbsd_ in ${ACCEPTABLE_NETBSD}
COMPAT_EXTRAS=	netbsd32_compat40-extras-${COMPAT_VERSION}{,nb*}:../../emulators/netbsd32_compat40-extras
.  endfor
.  if !empty(COMPAT_EXTRAS)
DEPENDS+=	${COMPAT_EXTRAS}
.  else
# XXX This package doesn't exist yet.
#DEPENDS+=	netbsd32_compat50>=5.0:../../emulators/netbsd32_compat50
.  endif
#
# We need to depend on the compat50 package to supply shared libraries
# missing from compat40 on NetBSD>5.x.
#
.elif empty(OS_VERSION:M[0-4].*) && empty(OS_VERSION:M5.[0-9]) && \
      empty(OS_VERSION:M5.[0-9].*) && empty(OS_VERSION:M5.[1-8][0-9].*) && \
      empty(OS_VERSION:M5.9[0-8]*)
# XXX This package doesn't exist yet.
#DEPENDS+=	compat50>=5.0:../../emulators/compat50
.endif

.include "../../mk/bsd.pkg.mk"
