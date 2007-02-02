# $NetBSD: Makefile,v 1.1.1.1 2007/02/02 16:08:47 drochner Exp $
#

DISTNAME=	wormux-0.7.9
CATEGORIES=	games
MASTER_SITES=	http://download.gna.org/wormux/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.wormux.org/
COMMENT=	Battle game

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_PKGLOCALEDIR= yes
USE_DIRS+=	xdg-1.1

WSHDIRS+= music/ingame music/menu
WSHDIRS+= gfx
WSHDIRS+= team/gnuteam team/thunderbirdteam team/spipteam team/beastieteam \
	team/oooteam team/tuxteam team/workraveteam team/konqiteam \
	team/firefoxteam team/wilberteam team/snortteam team/nupikteam \
	team/phpteam
WSHDIRS+= sound/share/menu sound/default sound/francais sound/flying
WSHDIRS+= weapon/jet_pack weapon/cluster_bomb weapon/syringe weapon/lowgrav \
	weapon/construct weapon/ninja_rope weapon/suicide weapon/disco_grenade \
	weapon/bazooka weapon/polecat weapon/shotgun weapon/mine weapon/sound \
	weapon/gun weapon/gnu weapon/teleportation weapon/snipe_rifle \
	weapon/supertux weapon/air_attack weapon/blowtorch weapon/m16 \
	weapon/grenade weapon/bounce_ball weapon/baseball weapon/airhammer \
	weapon/anvil weapon/dynamite weapon/parachute weapon/riot_bomb \
	weapon/skip_turn
WSHDIRS+= body/gnuteam body/thunderbirdteam body/spipteam body/beastieteam \
	body/oooteam body/tuxteam body/workraveteam body/konqiteam \
	body/firefoxteam body/wilberteam body/snortteam body/nupikteam \
	body/phpteam
WSHDIRS+= interface/cursors
WSHDIRS+= menu/img
WSHDIRS+= object
WSHDIRS+= font
WSHDIRS+= map/champignon map/paradis map/qingqong map/hell map/aquarium \
	map/desert map/monkeybubbleworld map/cowland map/grenouilles \
	map/leafs map/goodandevil map/arbre map/space map/cheese \
	map/wildwestdv map/noel map/electronik map/catacombes map/prehistorik \
	map/battlenight map/banquise map/pirates map/vulcano map/island \
	map/araignee map/halloween map/easterisland
WSHDIRS+= game_mode

pre-install:
	for d in ${WSHDIRS}; do \
	 ${INSTALL_DATA_DIR} ${PREFIX}/share/wormux/$$d; \
	done

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../devel/SDL_gfx/buildlink3.mk"
.include "../../net/SDL_net/buildlink3.mk"
.include "../../textproc/libxml++2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
