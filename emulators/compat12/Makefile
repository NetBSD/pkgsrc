# $NetBSD: Makefile,v 1.10 1998/08/20 15:16:52 tsarna Exp $
#

DISTNAME=	compat12-${MACHINE_ARCH}
PKGNAME=	compat12-1.2.1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	tv@netbsd.org
HOMEPAGE=	http://www.netbsd.org/Releases/formal-1.2/index.html

ONLY_FOR_ARCHS=	i386 m68k ns32k sparc

NO_BUILD=	yes

do-install:
	${INSTALL_DATA} ${WRKDIR}/lib*.so* ${PREFIX}/lib/

.include "../../mk/bsd.pkg.mk"
