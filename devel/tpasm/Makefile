# $NetBSD: Makefile,v 1.4 2003/03/29 12:40:41 jmmv Exp $
#

DISTNAME=	tpasm1.0r
PKGNAME=	tpasm-1.0r
WRKSRC=		${WRKDIR}/tpasm
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.ct0.com/pub/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.sqt.com
COMMENT=	assembler for 6805, 68HC11, 6502, Surplus, 8051, Z80, PIC, and AVR

USE_GMAKE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tpasm ${PREFIX}/bin
	${INSTALL_DATA_DIR}  ${PREFIX}/libdata/tpasm
	${INSTALL_DATA} ${WRKSRC}/include/* ${PREFIX}/libdata/tpasm/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tpasm
	${INSTALL_DATA} ${WRKSRC}/MANUAL.TXT ${PREFIX}/share/doc/tpasm

.include "../../mk/bsd.pkg.mk"
