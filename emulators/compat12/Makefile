# $NetBSD: Makefile,v 1.12 1999/04/27 11:53:39 tv Exp $
#

DISTNAME=	compat12-${MACHINE_ARCH}
PKGNAME=	compat12-1.2.1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	tv@netbsd.org
HOMEPAGE=	http://www.netbsd.org/Releases/formal-1.2/index.html

ONLY_FOR_ARCHS=	i386 m68k ns32k sparc
ONLY_FOR_OPSYS=	NetBSD

NO_BUILD=	yes

.include "../../mk/bsd.prefs.mk"

# This installs in /usr to avoid dynamic linker annoyances
LOCALBASE=	/usr 
NO_MTREE=	yes

do-install:
	${INSTALL_DATA} ${WRKDIR}/lib*.so* ${PREFIX}/lib/

.include "../../mk/bsd.pkg.mk"
