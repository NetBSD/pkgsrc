# $NetBSD: Makefile,v 1.14 2004/01/22 08:36:04 grant Exp $

DISTNAME=		hercules-2.11
PKGREVISION=		1
CATEGORIES=		emulators
MASTER_SITES=		http://www.conmicro.cx/hercules/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.conmicro.cx/hercules/
COMMENT=		S370 emulator

DEPENDS=		unproven-pthreads>0.17nb1:../../devel/unproven-pthreads
DEPENDS+=		hercules-images-[0-9]*:../../emulators/hercules-images

USE_GNU_TOOLS+=		make
MAKEFILE=		makefile
MAKE_ENV+=		HOST_ARCH=${MACHINE_ARCH}

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/hercules
	${INSTALL_DATA} ${WRKSRC}/hercules.cnf ${PREFIX}/share/examples/hercules/
	${INSTALL_DATA} ${WRKSRC}/zzsa.cnf ${PREFIX}/share/examples/hercules/

.include "../../mk/bsd.pkg.mk"
