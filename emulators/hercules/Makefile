# $NetBSD: Makefile,v 1.18 2005/12/05 20:50:11 rillig Exp $

DISTNAME=		hercules-2.11
PKGREVISION=		2
CATEGORIES=		emulators
MASTER_SITES=		http://www.conmicro.cx/hercules/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.conmicro.cx/hercules/
COMMENT=		S370 emulator

DEPENDS+=		hercules-images-[0-9]*:../../emulators/hercules-images

USE_TOOLS+=		gmake
MAKEFILE=		makefile
MAKE_ENV+=		HOST_ARCH=${MACHINE_ARCH:Q}

PTHREAD_OPTS+=		require

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/hercules
	${INSTALL_DATA} ${WRKSRC}/hercules.cnf ${PREFIX}/share/examples/hercules/
	${INSTALL_DATA} ${WRKSRC}/zzsa.cnf ${PREFIX}/share/examples/hercules/

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
