# $NetBSD: Makefile,v 1.14 2006/10/01 21:03:36 dillo Exp $
#

DISTNAME=	tavrasm
PKGNAME=	${DISTNAME}-1.22
CATEGORIES=	devel
MASTER_SITES=	http://www.tavrasm.org/

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://www.tavrasm.org/
COMMENT=	Assembler for the Atmel AVR series of microcontrollers

BUILD_DEPENDS+=	bison-[0-9]*:../../devel/bison

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV:S/.//:S/-/./}
BUILD_DIRS=	src
USE_TOOLS+=	lex
MAKE_FILE=	makefile

DIST_SUBDIR=	${PKGNAME_NOREV}

ONLY_FOR_COMPILER=	gcc
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tavrasm
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/tavrasm/README
	${INSTALL_PROGRAM} ${WRKSRC}/src/tavrasm ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tavrasm.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
