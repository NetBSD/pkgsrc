# $NetBSD: Makefile,v 1.8 2025/01/21 11:00:13 nia Exp $

.include "../../emulators/snes9x/Makefile.common"

PKGNAME=	libretro-snes9x-${SNES9X_VERSION}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/snes9x/
COMMENT=	Libretro core based on the snes9x Super Nintendo emulator

BUILD_DIRS=	libretro

LIBRETRO_CORE=	snes9x

FORCE_CXX_STD=	c++11

.include "../../emulators/retroarch/core.mk"
.include "../../mk/bsd.pkg.mk"
