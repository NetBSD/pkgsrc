# $NetBSD: Makefile,v 1.1 2013/02/17 17:24:09 spz Exp $

COMPAT_PKG=		compat60	# for compat_netbsd/Makefile.common
NETBSD_VERSION=		6.0

HOMEPAGE=		http://www.NetBSD.org/releases/formal-6/index.html
COMMENT=		Shared libraries for NetBSD 6.0 compatibility
# This license list is a pre-emptive strike, the actual situation may be better
LICENSE=		2-clause-bsd AND modified-bsd AND isc AND mit AND zlib \
			AND gnu-lgpl-v2 AND gnu-lgpl-v2.1 AND gnu-gpl-v2 \
			AND gnu-lgpl-v3 AND gnu-gpl-v3

DIST_SUBDIR=		20130213

EMUL_PLATFORMS=		netbsd-alpha netbsd-arm netbsd-i386 netbsd-m68k	\
			netbsd-mipseb netbsd-mipsel netbsd-powerpc	\
			netbsd-sparc netbsd-sparc64 netbsd-x86_64

ONLY_FOR_PLATFORM=	NetBSD-6.[1-9]*-* NetBSD-[7-9]*-* NetBSD-[1-9][0-9]*-*

.include "../../emulators/compat_netbsd/Makefile.common"

DISTNAME=		compat60-${EMUL_ARCH}-${COMPAT_VERSION}
COMPAT_VERSION=		6.0

# when 6.1 is out
#.if empty(OS_VERSION:M[0-5].*) && empty(OS_VERSION:M6.0*)
#DEPENDS+=	compat61>=6.1:../../emulators/compat61
#.endif

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
