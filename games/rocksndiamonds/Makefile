# $NetBSD: Makefile,v 1.69 2023/05/06 19:09:28 ryoon Exp $

DISTNAME=	rocksndiamonds-4.3.1.1

COMMENT=	Game like Boulder Dash, Emerald Mine, or Sokoban
PKGREVISION=	3

LEVEL_NAMES=	classic_boulderdash classic_emerald_mine classic_sokoban \
		classic_supaplex rnd_tutorial_aaron_davidson rnd_tutorial_niko_boehm

.include "Makefile.common"

MAKE_FLAGS+=	BASE_PATH=${PREFIX}/share/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
