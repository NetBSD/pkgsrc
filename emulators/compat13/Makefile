# $NetBSD: Makefile,v 1.3 1999/05/24 20:39:39 tv Exp $
#

DISTNAME=		compat13-${MACHINE_ARCH}
PKGNAME=		compat13-1.3.3
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		tv@netbsd.org
HOMEPAGE=		http://www.netbsd.org/Releases/formal-1.3/index.html

ONLY_FOR_PLATFORM=	NetBSD-*-{alpha,arm32,i386,m68k,mipsel,ns32k,sparc}
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
