# $NetBSD: Makefile,v 1.8 2016/10/15 00:45:15 kamil Exp $

DISTNAME=		bastet-0.43.1
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_GITHUB:=fph/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://fph.altervista.org/prog/bastet.html
COMMENT=		Bastard Tetris
LICENSE=		gnu-gpl-v3

USE_TOOLS+=		gmake
BUILD_DEFS+=		VARBASE

USE_GAMESGROUP=		yes
SPECIAL_PERMS=		bin/bastet ${SETGID_GAMES_PERMS}
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6

USE_LANGUAGES=	c++

SUBST_CLASSES+=		vardir
SUBST_STAGE.vardir=	pre-configure
SUBST_FILES.vardir=	Config.cpp
SUBST_MESSAGE.vardir=	Fixing VARBASE.
SUBST_SED.vardir=	-e "s|/var/games|${VARBASE}/games|1"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bastet ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/bastet.6 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man6/

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
