# $NetBSD: Makefile,v 1.1.1.1 2003/03/20 19:33:45 jmmv Exp $
#

DISTNAME=	z80-asm-1.0
CATEGORIES=	devel
MASTER_SITES=	http://virtus.ath.cx/z80/

MAINTAINER=	virtus@wanadoo.nl
HOMEPAGE=	http://artax.karlin.mff.cuni.cz/~brain/
COMMENT=	Z80 assembly code assembler and disassembler

GNU_CONFIGURE=	yes
USE_BUILDLINK2=	yes
USE_GMAKE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/z80-asm ${PREFIX}/bin/z80-asm
	${INSTALL_PROGRAM} ${WRKSRC}/z80-dis ${PREFIX}/bin/z80-dis
	${INSTALL_DATA} ${WRKSRC}/doc/z80-asm.1 ${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/doc/z80-dis.1 ${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/doc/z80-asm.5 ${PREFIX}/man/man5
	${INSTALL_DATA} ${WRKSRC}/doc/z80-file.5 ${PREFIX}/man/man5

.include "../../mk/bsd.pkg.mk"
