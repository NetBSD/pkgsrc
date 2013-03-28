# $NetBSD: Makefile,v 1.11 2013/03/28 23:59:03 joerg Exp $
#

DISTNAME=	z80-asm-1.0
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://virtus.ath.cx/z80/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://artax.karlin.mff.cuni.cz/~brain/
COMMENT=	Z80 assembly code assembler and disassembler

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man5

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/z80-asm ${DESTDIR}${PREFIX}/bin/z80-asm
	${INSTALL_PROGRAM} ${WRKSRC}/z80-dis ${DESTDIR}${PREFIX}/bin/z80-dis
	${INSTALL_DATA} ${WRKSRC}/doc/z80-asm.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/doc/z80-dis.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/doc/z80-asm.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5
	${INSTALL_DATA} ${WRKSRC}/doc/z80-file.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5

.include "../../mk/bsd.pkg.mk"
