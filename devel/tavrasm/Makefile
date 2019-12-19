# $NetBSD: Makefile,v 1.22 2019/12/19 22:13:48 joerg Exp $
#

DISTNAME=	tavrasm
PKGNAME=	${DISTNAME}-1.22
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_FREEBSD}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tavrasm.org/
COMMENT=	Assembler for the Atmel AVR series of microcontrollers

USE_LANGUAGES=	c++03

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV:S/.//:S/-/./}
BUILD_DIRS=	src
USE_TOOLS+=	lex bison
MAKE_FILE=	makefile

DIST_SUBDIR=	${PKGNAME_NOREV}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/tavrasm
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/tavrasm/README
	${INSTALL_PROGRAM} ${WRKSRC}/src/tavrasm ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tavrasm.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
