# $NetBSD: Makefile,v 1.3 2001/02/21 10:18:16 agc Exp $

DISTNAME=		hercules-2.11
CATEGORIES=		emulators
MASTER_SITES=		http://www.conmicro.cx/hercules/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.conmicro.cx/hercules/
COMMENT=		s370 emulator

DEPENDS=		unproven-pthreads-*:../../devel/unproven-pthreads

USE_GMAKE=		yes
MAKEFILE=		makefile

pre-install:
	${MKDIR} ${PREFIX}/share/examples/hercules
	${BSD_INSTALL_DATA} ${WRKSRC}/hercules.cnf ${PREFIX}/share/examples/hercules/
	${BSD_INSTALL_DATA} ${WRKSRC}/zzsa.cnf ${PREFIX}/share/examples/hercules/

.include "../../mk/bsd.pkg.mk"
