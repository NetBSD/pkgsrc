# $NetBSD: Makefile,v 1.2 2001/04/16 00:11:50 dmcmahill Exp $
#

DISTNAME=	tpasm1.0r
PKGNAME=	tpasm-1.0r
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.ct0.com/pub/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.sqt.com
COMMENT=	assembler for 6805, 68HC11, 6502, Surplus, 8051, Z80, PIC, and AVR

WRKSRC=		${WRKDIR}/tpasm

USE_GMAKE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tpasm ${PREFIX}/bin
	${INSTALL_DATA_DIR}  ${PREFIX}/libdata/tpasm
	${INSTALL_DATA} ${WRKSRC}/include/* ${PREFIX}/libdata/tpasm/

.include "../../mk/bsd.pkg.mk"
