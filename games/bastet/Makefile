# $NetBSD: Makefile,v 1.5 2012/10/06 11:54:30 asau Exp $
#

DISTNAME=		bastet-0.41
PKGREVISION=		1
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

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
