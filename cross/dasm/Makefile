# $NetBSD: Makefile,v 1.15 2020/12/01 14:55:54 fcambus Exp $

DISTNAME=	dasm-2.20.14.1
DIST_SUBDIR=	${PKGNAME_NOREV}
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_GITHUB:=dasm-assembler/}

MAINTAINER=	xmor61@users.sourceforge.net
HOMEPAGE=	https://dasm-assembler.github.io/
COMMENT=	Multi-CPU cross-assembler for 6502, 6803 and 68HC11
LICENSE=	gnu-gpl-v2

NO_CONFIGURE=	YES
USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin share/dasm ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/dasm ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/ftohex ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/docs/dasm.txt ${DESTDIR}${PREFIX}/share/dasm
	${INSTALL_DATA} ${WRKSRC}/docs/ftohex.txt ${DESTDIR}${PREFIX}/share/dasm
	${INSTALL_MAN} ${WRKSRC}/docs/dasm.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
