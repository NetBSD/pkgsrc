# $NetBSD: Makefile,v 1.12 2014/12/21 00:31:56 ryoon Exp $
#

DISTNAME=	z80-asm-2.3.7
CATEGORIES=	devel
MASTER_SITES=	http://wwwhomes.uni-bielefeld.de/achim/z80-asm/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wwwhomes.uni-bielefeld.de/achim/z80-asm.html
COMMENT=	Z80 assembly code assembler and disassembler
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man3
INSTALLATION_DIRS+=	${PKGMANDIR}/man5

INSTALL_MAKE_FLAGS+=	BIN_DIR=${DESTDIR}${PREFIX}/bin
INSTALL_MAKE_FLAGS+=	MAN_DIR=${DESTDIR}${PREFIX}/${PKGMANDIR}

.include "../../mk/bsd.pkg.mk"
