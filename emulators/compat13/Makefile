# $NetBSD: Makefile,v 1.2 1999/04/27 11:53:39 tv Exp $
#

DISTNAME=	compat13-${MACHINE_ARCH}
PKGNAME=	compat13-1.3.3
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	tv@netbsd.org
HOMEPAGE=	http://www.netbsd.org/Releases/formal-1.3/index.html

ONLY_FOR_ARCHS=	alpha arm32 i386 m68k mipsel ns32k sparc
ONLY_FOR_OPSYS=	NetBSD

# this is blank on "ineligible" version
OPSYS_VER!=	uname -r
.if (${OPSYS_VER:C/^1\.3.*//} == "")
IGNORE=		"NetBSD version not new enough: ${OPSYS_VER}"
.endif

NO_BUILD=	yes

.include "../../mk/bsd.prefs.mk"

# This installs in /usr to avoid dynamic linker annoyances
LOCALBASE=	/usr 
NO_MTREE=	yes

do-install:
	${INSTALL_DATA} ${WRKDIR}/lib*.so* ${PREFIX}/lib/
.if (${MACHINE_ARCH} == "mipsel")
	${LN} -sf ld.elf_so /usr/libexec/ld.so
.endif

.include "../../mk/bsd.pkg.mk"
