# $NetBSD: Makefile,v 1.67 2022/08/11 05:08:34 gutteridge Exp $

DISTNAME=	rocksndiamonds-4.3.1.1

COMMENT=	Game like Boulder Dash, Emerald Mine, or Sokoban
PKGREVISION=	1

LEVEL_NAMES=	classic_boulderdash classic_emerald_mine classic_sokoban \
		classic_supaplex rnd_tutorial_aaron_davidson rnd_tutorial_niko_boehm

.include "Makefile.common"

MAKE_FLAGS+=	BASE_PATH=${PREFIX}/share/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
