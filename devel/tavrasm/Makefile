# $NetBSD: Makefile,v 1.3 2001/02/25 04:17:43 hubertf Exp $
#

DISTNAME=	tavrasm
PKGNAME=	${DISTNAME}-1.15
CATEGORIES=	devel
MASTER_SITES=	http://www.tavrasm.org/

MAINTAINER=	dillo@giga.or.at
HOMEPAGE=	http://www.tavrasm.org/
COMMENT=	assembler for the Atmel AVR series of microcontrollers

BUILD_DEPENDS+=	bison:../../devel/bison

WRKSRCTOP=	${WRKDIR}/tavrasm.115
WRKSRC=		${WRKSRCTOP}/src
MAKEFILE=	makefile

DIST_SUBDIR=	${PKGNAME}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tavrasm
	${INSTALL_DATA} ${WRKSRCTOP}/README ${PREFIX}/share/doc/tavrasm/README
	${INSTALL_PROGRAM} ${WRKSRC}/tavrasm ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
