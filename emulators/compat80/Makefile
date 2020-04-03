# $NetBSD: Makefile,v 1.4 2020/04/03 06:17:25 wiz Exp $

COMPAT_PKG=		compat80	# for compat_netbsd/Makefile.common
NETBSD_VERSION=		8.0

HOMEPAGE=		https://www.NetBSD.org/releases/formal-8/index.html
COMMENT=		Shared libraries for NetBSD 8.0 compatibility
# This license list is a pre-emptive strike, the actual situation may be better
LICENSE=		2-clause-bsd AND modified-bsd AND isc AND mit AND zlib \
			AND gnu-lgpl-v2 AND gnu-lgpl-v2.1 AND gnu-gpl-v2 \
			AND gnu-lgpl-v3 AND gnu-gpl-v3

DIST_SUBDIR=		20191014

EMUL_PLATFORMS=		netbsd-alpha \
			netbsd-arm netbsd-armeb netbsd-armv6hf netbsd-armv7hf \
			netbsd-earm netbsd-earmv7hfeb \
			netbsd-i386 netbsd-m68k	\
			netbsd-mips64eb netbsd-mips64el \
			netbsd-mipseb netbsd-mipsel \
			netbsd-powerpc \
			netbsd-sh3eb netbsd-sh3el \
			netbsd-sparc netbsd-sparc64 \
			netbsd-vax \
			netbsd-x86_64


# select ONLY_FOR_PLATFORM start by the osversion we diffed against
# add NetBSD-8.[1-9]*-* once 8.1 is out and we have compat81
ONLY_FOR_PLATFORM=	NetBSD-9*-* NetBSD-[1-9][0-9]*-*

CHECK_RELRO_SKIP=	*

.include "../../emulators/compat_netbsd/Makefile.common"

DISTNAME=		compat80-${EMUL_ARCH}-${COMPAT_VERSION}
COMPAT_VERSION=		8.0

# when 8.1 is out, one could do:
#.if empty(OS_VERSION:M[0-7].*) && empty(OS_VERSION:M8.[0-1]*)
#DEPENDS+=	compat81>=8.1:../../emulators/compat81
#.endif

.include "../../mk/bsd.pkg.mk"
