# $NetBSD: Makefile,v 1.9 1998/08/17 18:35:34 tv Exp $
#

DISTNAME=	compat12-${MACHINE_ARCH}
PKGNAME=	compat12-1.2.1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	tv@netbsd.org

ONLY_FOR_ARCHS=	i386 m68k ns32k sparc

NO_BUILD=	yes

do-install:
	${INSTALL_DATA} ${WRKDIR}/lib*.so* ${PREFIX}/lib/

.include "../../mk/bsd.pkg.mk"
