# $NetBSD: Makefile,v 1.7 2001/05/08 23:23:49 dmcmahill Exp $

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
MAKE_ENV+=		HOST_ARCH=${MACHINE_ARCH}

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/hercules
	${BSD_INSTALL_DATA} ${WRKSRC}/hercules.cnf ${PREFIX}/share/examples/hercules/
	${BSD_INSTALL_DATA} ${WRKSRC}/zzsa.cnf ${PREFIX}/share/examples/hercules/

.include "../../mk/bsd.pkg.mk"
