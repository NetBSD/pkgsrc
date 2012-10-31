# $NetBSD: Makefile,v 1.18 2012/10/31 11:19:51 asau Exp $
#

DISTNAME=	tpasm1.0r
PKGNAME=	tpasm-1.0r
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.ct0.com/pub/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.sqt.com/
COMMENT=	Assembler for 6805, 68HC11, 6502, Surplus, 8051, Z80, PIC, and AVR

WRKSRC=		${WRKDIR}/tpasm
USE_LANGUAGES=	c++
USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/libdata/tpasm
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/tpasm
	${INSTALL_PROGRAM} ${WRKSRC}/tpasm ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/include/* ${DESTDIR}${PREFIX}/libdata/tpasm
	${INSTALL_DATA} ${WRKSRC}/MANUAL.TXT ${DESTDIR}${PREFIX}/share/doc/tpasm

.include "../../mk/bsd.pkg.mk"
