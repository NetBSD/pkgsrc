# $NetBSD: Makefile,v 1.10 2004/06/12 12:40:21 grant Exp $
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

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tavrasm
	${INSTALL_DATA} ${WRKSRCTOP}/README ${PREFIX}/share/doc/tavrasm/README
	${INSTALL_PROGRAM} ${WRKSRC}/tavrasm ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
