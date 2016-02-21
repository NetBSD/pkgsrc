# $NetBSD: Makefile,v 1.13 2016/02/21 07:40:39 ryoon Exp $
#

DISTNAME=	z80-asm-2.3.7
PKGREVISION=	1
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

# Fix install under case insensitive file system.
INSTALL_TARGET=		install-all

INSTALLATION_DIRS+=	share/doc/${PKGBASE}
Z80ASM_DOCS+=	CHANGELOG README SRC_FILES TODO dizz80.dvi dizz80.ps \
		execute_timing.txt z80-asm.html Z80-cpu-pins z80-decoder.c \
		z80-decoder.h z80-mon.html z80instructions.txt \
		z80mnemonics.txt etc/ti86ports.txt

post-install:
.for f in ${Z80ASM_DOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
.endfor


.include "../../mk/bsd.pkg.mk"
