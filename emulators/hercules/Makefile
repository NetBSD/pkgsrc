# $NetBSD: Makefile,v 1.1.1.1 2001/02/19 12:35:21 agc Exp $

DISTNAME=		hercules-2.11
CATEGORIES=		emulators
MASTER_SITES=		http://www.conmicro.cx/hercules/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.snes9x.com/
COMMENT=		s370 emulator

DEPENDS=		pth-*:../../devel/pth

USE_GMAKE=		yes
MAKEFILE=		makefile

pre-install:
	${MKDIR} ${PREFIX}/share/examples/hercules
	${BSD_INSTALL_DATA} ${WRKSRC}/hercules.cnf ${PREFIX}/share/examples/hercules/
	${BSD_INSTALL_DATA} ${WRKSRC}/zzsa.cnf ${PREFIX}/share/examples/hercules/

.include "../../mk/bsd.pkg.mk"
