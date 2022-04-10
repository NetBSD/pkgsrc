# $NetBSD: Makefile,v 1.66 2022/04/10 12:18:19 adam Exp $

DISTNAME=	rocksndiamonds-4.3.1.1

COMMENT=	Game like Boulder Dash, Emerald Mine, or Sokoban

LEVEL_NAMES=	classic_boulderdash classic_emerald_mine classic_sokoban \
		classic_supaplex rnd_tutorial_aaron_davidson rnd_tutorial_niko_boehm

.include "Makefile.common"

MAKE_FLAGS+=	BASE_PATH=${PREFIX}/share/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
