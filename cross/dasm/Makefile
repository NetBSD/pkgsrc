# $NetBSD: Makefile,v 1.10 2013/06/16 09:40:58 ryoon Exp $
#

DISTNAME=	dasm-2.20.11
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dasm-dillon/}

MAINTAINER=	xmor61@users.sourceforge.net
HOMEPAGE=	http://dasm-dillon.sourceforge.net/
COMMENT=	Multi-CPU cross-assembler for 6502, 6803 and 68HC11
LICENSE=	gnu-gpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_CONFIGURE=	YES
USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin share/dasm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/dasm ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/ftohex ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/doc/dasm.txt ${DESTDIR}${PREFIX}/share/dasm
	${INSTALL_DATA} ${WRKSRC}/doc/ftohex.txt ${DESTDIR}${PREFIX}/share/dasm

.include "../../mk/bsd.pkg.mk"
