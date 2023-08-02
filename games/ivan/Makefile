# $NetBSD: Makefile,v 1.23 2023/08/02 19:21:52 nia Exp $
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

USE_LANGUAGES=		c c++

# Fails with C++14 default language.
FORCE_CXX_STD=		c++03

REQD_DIRS+=		share/ivan
OWN_DIRS_PERMS+=	share/ivan/Bones ${GAMES_USER} ${GAMES_GROUP} ${GAMEDIRMODE}
CONF_FILES_PERMS+=	/dev/null ${PREFIX}/share/ivan/ivan-highscore.scores \
			${GAMES_USER} ${GAMES_GROUP} ${GAMEDATAMODE}
SPECIAL_PERMS+=		bin/ivan ${SETGID_GAMES_PERMS}

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
