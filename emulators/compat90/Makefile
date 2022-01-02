# $NetBSD: Makefile,v 1.3 2022/01/02 16:35:12 he Exp $

COMPAT_PKG=		compat90	# for compat_netbsd/Makefile.common
NETBSD_VERSION=		9.0
PKGREVISION=		1

HOMEPAGE=		https://www.NetBSD.org/releases/formal-9/index.html
COMMENT=		Shared libraries for NetBSD 9.0 compatibility
# This license list is a pre-emptive strike, the actual situation may be better
LICENSE=		2-clause-bsd AND modified-bsd AND isc AND mit AND zlib \
			AND gnu-lgpl-v2 AND gnu-lgpl-v2.1 AND gnu-gpl-v2 \
			AND gnu-lgpl-v3 AND gnu-gpl-v3

DIST_SUBDIR=		20211116

EMUL_PLATFORMS=		netbsd-aarch64 \
			netbsd-alpha \
			netbsd-arm netbsd-earmeb \
			netbsd-earmv6hf netbsd-earmv7hf \
			netbsd-earmv7hfeb \
			netbsd-i386 netbsd-m68000 netbsd-m68k \
			netbsd-mips64eb netbsd-mips64el \
			netbsd-mipseb netbsd-mipsel \
			netbsd-powerpc \
			netbsd-sh3eb netbsd-sh3el \
			netbsd-sparc netbsd-sparc64 \
			netbsd-vax \
			netbsd-x86_64


# select ONLY_FOR_PLATFORM start by the osversion we diffed against
ONLY_FOR_PLATFORM=	NetBSD-9.99.*-* NetBSD-[1-9][0-9].*-*

CHECK_RELRO_SKIP=	*

.include "../../emulators/compat_netbsd/Makefile.common"

DISTNAME=		compat90-${EMUL_ARCH}-${COMPAT_VERSION}
COMPAT_VERSION=		9.0

.include "../../mk/bsd.pkg.mk"
