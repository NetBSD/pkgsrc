# $NetBSD: Makefile,v 1.16 2012/10/06 11:54:53 asau Exp $

DISTNAME=	rocksndiamonds-levels-1.0
PKGREVISION=	3
CATEGORIES=	games x11
MASTER_SITES=	http://www.artsoft.org/RELEASES/unix/rocksndiamonds/levels/
DISTFILES=	rockslevels-dx-1.0.tar.gz \
		rockslevels-emc-1.0.tar.gz \
		rockslevels-sp-1.0.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.artsoft.org/rocksndiamonds/levels.html
COMMENT=	DX, Emerald Mine, and Sokoban levels for Rocks'N'Diamonds

DEPENDS+=	rocksndiamonds{,-sdl}>=1.4.0:../../games/rocksndiamonds

NO_CONFIGURE=	yes
NO_BUILD=	yes
USE_LANGUAGES=	# none
WRKSRC=		${WRKDIR}/levels

INSTALLATION_DIRS=	share/rocksndiamonds/levels

PLIST_SRC=	${WRKDIR}/PLIST ${PKGDIR}/PLIST

# if you change SCORE_PATH, don't forget to change patch-aa, too
SCORE_PATH=	${VARBASE}/games/rocksndiamonds

CPIO?=		cpio

post-extract:
	${CHMOD} -R o-w ${WRKSRC}

SETGIDGAME=		yes
MAKE_DIRS_PERMS=	${SCORE_PATH} ${GAMES_USER} ${GAMES_GROUP} ${GAMEDIRMODE}
MAKE_DIRS_PERMS+=	${SCORE_PATH}/scores ${GAMES_USER} ${GAMES_GROUP} ${GAMEDIRMODE}

.for directory in dx_abd dx_achim_haertel \
	dx_bd4 dx_blunderdash dx_boulderdash5 dx_dc2classic dx_firefox1 \
	dx_forgottenmine1 dx_manfred_tausch dx_martin_brentnall \
	dx_no_one_1-3 dx_no_one_4-6 dx_peter_broadribb dx_tutorial \
	emc_acemine_1 emc_acemine_2 emc_adventures_of_mr_b_1 \
	emc_adventures_of_mr_b_2 emc_amidash emc_babyghostmine emc_bd_c64 \
	emc_beermine emc_bobbydash emc_bondmine_01 emc_bondmine_02 \
	emc_bondmine_03 emc_bondmine_04 emc_bondmine_05 emc_bondmine_06 \
	emc_bondmine_07_5 emc_bondmine_08 emc_bondmine_09 emc_bondmine_11 \
	emc_bondmine_12 emc_bondmine_13 emc_bugmine_2 emc_bugmine_4 \
	emc_cosmos_mine emc_crystal_caverns_1 emc_crystal_caverns_2 \
	emc_crystal_caverns_3 emc_crystal_caverns_4 emc_danmark_mine_1 \
	emc_danmark_mine_2 emc_denmine_01 emc_denmine_02 emc_denmine_03 \
	emc_denmine_04 emc_denmine_05 emc_denmine_06 emc_denmine_07 \
	emc_denmine_08 emc_denmine_09 emc_denmine_10 emc_denmine_11 \
	emc_denmine_12 emc_downunder_mine_01 emc_downunder_mine_03 \
	emc_downunder_mine_04 emc_downunder_mine_05 emc_downunder_mine_06 \
	emc_downunder_mine_07 emc_downunder_mine_08 emc_downunder_mine_09 \
	emc_downunder_mine_10 emc_downunder_mine_11 emc_downunder_mine_13 \
	emc_downunder_mine_14 emc_downunder_mine_19 emc_downunder_mine_21 \
	emc_easy_ruppelmine emc_eatmine_1 emc_eatmine_2 emc_eatmine_3 \
	emc_emerald_cruncher_2 emc_emerald_dash emc_emerald_eater_1 \
	emc_emerald_eater_2 emc_emerald_freak_1 emc_emerald_freak_2 \
	emc_emerald_head emc_emerald_mine_01 emc_emerald_mine_02 \
	emc_emerald_mine_03 emc_emerald_mine_03_pro emc_emerald_mine_04 \
	emc_emerald_mine_04_pro_x emc_emerald_mine_05 emc_emerald_mine_06 \
	emc_emerald_mine_07 emc_emerald_mine_08 emc_emerald_mine_09 \
	emc_emerald_mine_10 emc_emerald_mine_11 emc_emerald_mine_12 \
	emc_emerald_mine_13 emc_emerald_mine_14 emc_emerald_mine_15 \
	emc_emerald_mine_16 emc_emerald_mine_17 emc_emerald_mine_18 \
	emc_emerald_mine_final emc_emerald_runner_mine emc_exception_one \
	emc_expert_mine_1 emc_expert_mine_2 emc_expert_mine_3 emc_fun_mine \
	emc_gold_nuggets_1 emc_gold_nuggets_2 emc_haunted_mine_3 \
	emc_into_cold_caves emc_into_frusty_mines emc_into_future_fields \
	emc_into_history_holes emc_laser_bd_2 emc_no_one_10 emc_profi_bd_1 \
	emc_profi_bd_2 emc_recycled_1 emc_recycled_2 emc_ruppelmine_1 \
	emc_ruppelmine_2 emc_ruppelmine_3 emc_tutorial_2 emc_venom_mine \
	supaplex_01 supaplex_02 supaplex_03 supaplex_04 supaplex_05 \
	supaplex_06 supaplex_07 supaplex_08 supaplex_95 supaplex_96 \
	supaplex_97 supaplex_98 supaplex_99
OWN_DIRS_PERMS+=	${SCORE_PATH}/scores/${directory} \
			${GAMES_USER} ${GAMES_GROUP} ${GAMEDIRMODE}
.endfor

do-install:
	cd ${WRKSRC} && ${FIND} DX_Boulderdash Emerald_Mine_Club Supaplex | \
		${CPIO} -p ${DESTDIR}${PREFIX}/share/rocksndiamonds/levels
	${RM} -f ${WRKDIR}/PLIST
.for levdir in DX_Boulderdash Emerald_Mine_Club Supaplex
	cd ${DESTDIR}${PREFIX} && \
	${FIND} share/rocksndiamonds/levels/${levdir} -type f -print \
		>>${WRKDIR}/PLIST
.endfor

.include "../../mk/bsd.pkg.mk"
