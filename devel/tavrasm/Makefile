# $NetBSD: Makefile,v 1.8 2003/09/11 18:08:44 jmmv Exp $
#

DISTNAME=	tavrasm
PKGNAME=	${DISTNAME}-1.19
CATEGORIES=	devel
MASTER_SITES=	http://www.tavrasm.org/

MAINTAINER=	dillo@giga.or.at
HOMEPAGE=	http://www.tavrasm.org/
COMMENT=	Assembler for the Atmel AVR series of microcontrollers

BUILD_DEPENDS+=	bison-[0-9]*:../../devel/bison

WRKSRCTOP=	${WRKDIR}/${PKGNAME_NOREV:S/.//:S/-/./}
WRKSRC=		${WRKSRCTOP}/src
MAKEFILE=	makefile

DIST_SUBDIR=	${PKGNAME}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tavrasm
	${INSTALL_DATA} ${WRKSRCTOP}/README ${PREFIX}/share/doc/tavrasm/README
	${INSTALL_PROGRAM} ${WRKSRC}/tavrasm ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
