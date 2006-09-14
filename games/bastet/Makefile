# $NetBSD: Makefile,v 1.2 2006/09/14 20:53:24 dogcow Exp $
#

DISTNAME=		bastet-0.41
CATEGORIES=		games
MASTER_SITES=		http://fph.altervista.org/prog/
EXTRACT_SUFX=		.tgz

MAINTAINER=		rillig@NetBSD.org
HOMEPAGE=		http://fph.altervista.org/prog/bastet.shtml
COMMENT=		Bastard Tetris

USE_TOOLS+=		gmake
MAKE_FLAGS+=		BIN_PREFIX=${PREFIX}/bin/
MAKE_FLAGS+=		DATA_PREFIX=${VARBASE}/games/
BUILD_DEFS+=		VARBASE

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6

do-install:
	${INSTALL_GAME} ${WRKSRC}/bastet ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/bastet.6 ${PREFIX}/${PKGMANDIR}/man6/

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
