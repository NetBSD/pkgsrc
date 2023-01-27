# $NetBSD: Makefile,v 1.2 2023/01/27 23:22:31 thorpej Exp $

DISTNAME=	z80asm-1.8
CATEGORIES=	cross
MASTER_SITES=	https://download.savannah.nongnu.org/releases/z80asm/

PKGREVISION=	1

MAINTAINER=	thorpej@NetBSD.org
HOMEPAGE=	https://savannah.nongnu.org/projects/z80asm/
COMMENT=	Assembler for the Z80 microprcessor
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/z80asm \
	    ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/z80asm.1 \
	    ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
