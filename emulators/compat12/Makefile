# $NetBSD: Makefile,v 1.13 1999/05/24 20:39:39 tv Exp $
#

DISTNAME=		compat12-${MACHINE_ARCH}
PKGNAME=		compat12-1.2.1
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		tv@netbsd.org
HOMEPAGE=		http://www.netbsd.org/Releases/formal-1.2/index.html

ONLY_FOR_PLATFORM=	NetBSD-*-{i386,m68k,ns32k,sparc}

NO_BUILD=

.include "../../mk/bsd.prefs.mk"

# This installs in /usr to avoid dynamic linker annoyances
LOCALBASE=	/usr 
NO_MTREE=

do-install:
	${INSTALL_DATA} ${WRKDIR}/lib*.so* ${PREFIX}/lib/

.include "../../mk/bsd.pkg.mk"
