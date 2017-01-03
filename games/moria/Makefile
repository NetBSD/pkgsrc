# $NetBSD: Makefile,v 1.19 2017/01/03 21:50:53 roy Exp $

DISTNAME=		um5.5.2
PKGNAME=		moria-5.5.2
PKGREVISION=		5
CATEGORIES=		games
# The "offical" master site has lost the pub/Games directory.
#MASTER_SITES=		ftp://ftp.cis.ksu.edu/pub/Games/Moria/source/
MASTER_SITES=		ftp://ftp.funet.fi/pub/unix/games/moria/source/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		simonb@NetBSD.org
HOMEPAGE=		http://remarque.org/~grabiner/moria.html
#HOMEPAGE=		http://www-math.bgsu.edu/~grabine/moria.html
COMMENT=		Rogue-like game with a different sense of scale than Rogue

WRKSRC=			${WRKDIR}/umoria
MAKE_FLAGS+=		CURSES=-l${BUILDLINK_LIBNAME.curses} VARBASE=${VARBASE}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6

SETGIDGAME=		yes
CONF_FILES_PERMS+=	/dev/null ${VARBASE}/games/moria.scores \
			${GAMES_USER} ${GAMES_GROUP} ${GAMEDATAMODE}
SPECIAL_PERMS=		bin/moria ${SETGID_GAMES_PERMS}

do-configure:
	@${RM} -f ${WRKSRC}/*.[ch] ${WRKSRC}/Makefile
	@cd ${WRKSRC}; ${LN} -s source/* unix/* .

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
