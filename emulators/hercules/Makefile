# $NetBSD: Makefile,v 1.5 2001/02/25 04:17:45 hubertf Exp $

DISTNAME=		hercules-2.11
CATEGORIES=		emulators
MASTER_SITES=		http://www.conmicro.cx/hercules/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.conmicro.cx/hercules/
COMMENT=		s370 emulator

DEPENDS=		unproven-pthreads-*:../../devel/unproven-pthreads
DEPENDS+=		hercules-images-*:../../emulators/hercules-images

USE_GMAKE=		yes
MAKEFILE=		makefile

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/hercules
	${BSD_INSTALL_DATA} ${WRKSRC}/hercules.cnf ${PREFIX}/share/examples/hercules/
	${BSD_INSTALL_DATA} ${WRKSRC}/zzsa.cnf ${PREFIX}/share/examples/hercules/

.include "../../mk/bsd.pkg.mk"
