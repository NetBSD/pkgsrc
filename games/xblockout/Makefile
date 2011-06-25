# $NetBSD: Makefile,v 1.6 2011/06/25 11:32:09 obache Exp $
#

DISTNAME=	xbl-1.1.6
CATEGORIES=	games
MASTER_SITES=	http://www710.univ-lyon1.fr/~exco/XBL/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www710.univ-lyon1.fr/ftp/xbl/xbl.html
COMMENT=	3D-tetris-like game
LICENSE=	gnu-gpl-v1

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	imake
GNU_CONFIGURE=	yes
USE_GAMESGROUP=	yes

# libXext is not needed
BUILDLINK_TRANSFORM+=	rm:-lXext
INSTALLATION_DIRS=	bin lib/X11/app-defaults

USERGROUP_PHASE=	configure

SUBST_CLASSES+=		gamegid
SUBST_STAGE.gamegid=	pre-configure
SUBST_FILES.gamegid=	Makefile.in
SUBST_SED.gamegid=	-e 's/@GROUP_GID@/GROUP_GID=${PKG_GID.${GAMES_GROUP}}/g'

SPECIAL_PERMS+=		bin/xbl ${SETGID_GAMES_PERMS}
OWN_DIRS_PERMS+=	${PREFIX}/lib/X11/xbl ${GAMEDIR_PERMS}

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
