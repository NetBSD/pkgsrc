# $NetBSD: Makefile,v 1.22 2020/03/20 11:57:42 nia Exp $
#

DISTNAME=		ivan-0.50
PKGREVISION=		10
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ivan/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://ivan.sourceforge.net/
COMMENT=		Graphical roguelike featuring deep gameplay
LICENSE=		gnu-gpl-v2 # or later

USE_TOOLS+=		gmake
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--localstatedir=${PREFIX}/share

USE_LANGUAGES=		c c++03

REQD_DIRS+=		share/ivan
OWN_DIRS_PERMS+=	share/ivan/Bones ${GAMES_USER} ${GAMES_GROUP} ${GAMEDIRMODE}
CONF_FILES_PERMS+=	/dev/null ${PREFIX}/share/ivan/ivan-highscore.scores \
			${GAMES_USER} ${GAMES_GROUP} ${GAMEDATAMODE}
SPECIAL_PERMS+=		bin/ivan ${SETGID_GAMES_PERMS}

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
