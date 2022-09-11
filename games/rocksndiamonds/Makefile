# $NetBSD: Makefile,v 1.68 2022/09/11 12:51:47 wiz Exp $

DISTNAME=	rocksndiamonds-4.3.1.1

COMMENT=	Game like Boulder Dash, Emerald Mine, or Sokoban
PKGREVISION=	2

LEVEL_NAMES=	classic_boulderdash classic_emerald_mine classic_sokoban \
		classic_supaplex rnd_tutorial_aaron_davidson rnd_tutorial_niko_boehm

.include "Makefile.common"

MAKE_FLAGS+=	BASE_PATH=${PREFIX}/share/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
