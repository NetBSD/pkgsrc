# $NetBSD: Makefile,v 1.6 2001/03/23 16:20:55 agc Exp $

DISTNAME=		hercules-2.11
PKGNAME=		${DISTNAME}nb1
CATEGORIES=		emulators
MASTER_SITES=		http://www.conmicro.cx/hercules/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.conmicro.cx/hercules/
COMMENT=		s370 emulator

DEPENDS=		unproven-pthreads>0.17nb1:../../devel/unproven-pthreads
DEPENDS+=		hercules-images-*:../../emulators/hercules-images

USE_GMAKE=		yes
MAKEFILE=		makefile

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/hercules
	${BSD_INSTALL_DATA} ${WRKSRC}/hercules.cnf ${PREFIX}/share/examples/hercules/
	${BSD_INSTALL_DATA} ${WRKSRC}/zzsa.cnf ${PREFIX}/share/examples/hercules/

.include "../../mk/bsd.pkg.mk"
