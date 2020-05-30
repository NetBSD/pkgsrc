# $NetBSD: Makefile,v 1.4 2020/05/30 14:52:27 nia Exp $

DISTNAME=	libretro-beetle-pce-fast-20200523
CATEGORIES=	emulators
GITHUB_PROJECT=	beetle-pce-fast-libretro
GITHUB_TAG=	17ba58b4695970dad499de04a3b81777ff47c9d9

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/beetle_pce_fast/
COMMENT=	Libretro core based on the Mednafen PC Engine emulator
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++

LIBRETRO_CORE=	mednafen_pce_fast

.include "../../emulators/retroarch/core.mk"

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=link.T

.include "../../mk/bsd.pkg.mk"
