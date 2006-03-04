# $NetBSD: Makefile,v 1.15 2006/03/04 21:29:30 jlam Exp $
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
USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/libdata/tpasm
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tpasm
	${INSTALL_PROGRAM} ${WRKSRC}/tpasm ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/include/* ${PREFIX}/libdata/tpasm
	${INSTALL_DATA} ${WRKSRC}/MANUAL.TXT ${PREFIX}/share/doc/tpasm

.include "../../mk/bsd.pkg.mk"
