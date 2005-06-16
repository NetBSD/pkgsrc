# $NetBSD: Makefile,v 1.11 2005/06/16 06:57:48 jlam Exp $
#

DISTNAME=	tavrasm
PKGNAME=	${DISTNAME}-1.20
CATEGORIES=	devel
MASTER_SITES=	http://www.tavrasm.org/

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://www.tavrasm.org/
COMMENT=	Assembler for the Atmel AVR series of microcontrollers

BUILD_DEPENDS+=	bison-[0-9]*:../../devel/bison

WRKSRCTOP=	${WRKDIR}/${PKGNAME_NOREV:S/.//:S/-/./}
WRKSRC=		${WRKSRCTOP}/src
MAKEFILE=	makefile

DIST_SUBDIR=	${PKGNAME_NOREV}

ONLY_FOR_COMPILER=	gcc
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tavrasm
	${INSTALL_DATA} ${WRKSRCTOP}/README ${PREFIX}/share/doc/tavrasm/README
	${INSTALL_PROGRAM} ${WRKSRC}/tavrasm ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
