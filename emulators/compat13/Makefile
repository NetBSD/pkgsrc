# $NetBSD: Makefile,v 1.4 1999/06/20 21:06:19 tron Exp $
#

DISTNAME=		compat13-${MACHINE_ARCH}
PKGNAME=		compat13-1.3.3
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		tv@netbsd.org
HOMEPAGE=		http://www.netbsd.org/Releases/formal-1.3/index.html

ONLY_FOR_PLATFORM=	NetBSD-*-alpha NetBSD-*-arm32 NetBSD-*-i386 \
			NetBSD-*-m68k NetBSD-*-mipsel NetBSD-*-ns32k \
			NetBSD-*-sparc
NOT_FOR_PLATFORM=	NetBSD-1.3*-*

NO_BUILD=

.include "../../mk/bsd.prefs.mk"

# This installs in /usr to avoid dynamic linker annoyances
LOCALBASE=		/usr 
NO_MTREE=

do-install:
	${INSTALL_DATA} ${WRKDIR}/lib*.so* ${PREFIX}/lib/
.if (${MACHINE_ARCH} == "mipsel")
	${LN} -sf ld.elf_so /usr/libexec/ld.so
.endif

.include "../../mk/bsd.pkg.mk"
