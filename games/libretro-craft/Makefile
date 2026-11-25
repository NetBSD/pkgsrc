# $NetBSD: Makefile,v 1.5 2026/11/25 14:42:09 wiz Exp $

DISTNAME=	libretro-craft-20200504
CATEGORIES=	games
GITHUB_PROJECT=	Craft
GITHUB_TAG=	1b0da2b133a528f352c4b6dc24a464c652e39630

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/craft
COMMENT=	Libretro core based on the 'Craft' Minecraft clone
LICENSE=	mit

LIBRETRO_CORE=	craft

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=./link.T

.include "../../emulators/retroarch/core.mk"
.include "../../mk/mesa.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
