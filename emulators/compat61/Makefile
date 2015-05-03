# $NetBSD: Makefile,v 1.1 2015/05/03 15:01:12 spz Exp $

COMPAT_PKG=		compat61	# for compat_netbsd/Makefile.common
NETBSD_VERSION=		6.1

HOMEPAGE=		http://www.NetBSD.org/releases/formal-6/index.html
COMMENT=		Shared libraries for NetBSD 6.1 compatibility
# This license list is a pre-emptive strike, the actual situation may be better
LICENSE=		2-clause-bsd AND modified-bsd AND isc AND mit AND zlib \
			AND gnu-lgpl-v2 AND gnu-lgpl-v2.1 AND gnu-gpl-v2 \
			AND gnu-lgpl-v3 AND gnu-gpl-v3

DIST_SUBDIR=		20150430

EMUL_PLATFORMS=		netbsd-alpha netbsd-arm netbsd-i386 netbsd-m68k	\
			netbsd-mipseb netbsd-mipsel \
			netbsd-mips64eb netbsd-mips64el \
			netbsd-powerpc	\
			netbsd-sparc netbsd-sparc64 netbsd-x86_64

# select ONLY_FOR_PLATFORM start by the osversion we diffed against
# add NetBSD-6.[2-9]*-* once 6.2 is out and we have compat62
ONLY_FOR_PLATFORM=	NetBSD-[7-9]*-* NetBSD-[1-9][0-9]*-*

.include "../../emulators/compat_netbsd/Makefile.common"

DISTNAME=		compat61-${EMUL_ARCH}-${COMPAT_VERSION}
COMPAT_VERSION=		6.1

# when 6.2 is out
#.if empty(OS_VERSION:M[0-5].*) && empty(OS_VERSION:M6.[0-2]*)
#DEPENDS+=	compat62>=6.2:../../emulators/compat62
#.endif

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
