# $NetBSD: Makefile,v 1.21 2006/09/09 02:41:59 obache Exp $

DISTNAME=		hercules-2.11
PKGREVISION=		3
CATEGORIES=		emulators
MASTER_SITES=		http://www.conmicro.cx/hercules/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.conmicro.cx/hercules/
COMMENT=		S370 emulator

DEPENDS+=		hercules-images-[0-9]*:../../emulators/hercules-images

USE_TOOLS+=		gmake
MAKE_FILE=		makefile
MAKE_ENV+=		HOST_ARCH=${MACHINE_ARCH:Q}

PTHREAD_OPTS+=		require

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/hercules
	${INSTALL_DATA} ${WRKSRC}/hercules.cnf ${PREFIX}/share/examples/hercules/
	${INSTALL_DATA} ${WRKSRC}/zzsa.cnf ${PREFIX}/share/examples/hercules/

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
