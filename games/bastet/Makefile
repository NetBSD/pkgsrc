# $NetBSD: Makefile,v 1.6 2013/10/17 09:19:01 roy Exp $
#

DISTNAME=		bastet-0.41
PKGREVISION=		2
CATEGORIES=		games
MASTER_SITES=		http://fph.altervista.org/prog/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://fph.altervista.org/prog/bastet.shtml
COMMENT=		Bastard Tetris

USE_TOOLS+=		gmake
MAKE_FLAGS+=		BIN_PREFIX=${PREFIX}/bin/
MAKE_FLAGS+=		DATA_PREFIX=${VARBASE}/games/
BUILD_DEFS+=		VARBASE

SETGIDGAME=		yes
SPECIAL_PERMS=		bin/bastet ${SETGID_GAMES_PERMS}
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bastet ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/bastet.6 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man6/

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
