# $NetBSD: Makefile,v 1.13 2012/05/23 06:05:39 dholland Exp $

DISTNAME=		um5.5.2
PKGNAME=		moria-5.5.2
PKGREVISION=		2
CATEGORIES=		games
# The "offical" master site has lost the pub/Games directory.
#MASTER_SITES=		ftp://ftp.cis.ksu.edu/pub/Games/Moria/source/
MASTER_SITES=		ftp://ftp.funet.fi/pub/unix/games/moria/source/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		simonb@NetBSD.org
HOMEPAGE=		http://www-math.bgsu.edu/~grabine/moria.html
COMMENT=		Rogue-like game with a different sense of scale than Rogue

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/umoria
MAKE_FLAGS+=		CURSES=-lncurses

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6

SETGIDGAME=		yes
CONF_FILES_PERMS+=	/dev/null ${VARBASE}/games/moria.scores \
			${GAMES_USER} ${GAMES_GROUP} ${GAMEDATAMODE}
SPECIAL_PERMS=		bin/moria ${SETGID_GAMES_PERMS}

do-configure:
	@${RM} -f ${WRKSRC}/*.[ch] ${WRKSRC}/Makefile
	@cd ${WRKSRC}; ${LN} -s source/* unix/* .

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
