# $NetBSD: Makefile,v 1.7 2024/02/21 11:31:21 nia Exp $

.include "../../emulators/snes9x/Makefile.common"

PKGNAME=	libretro-snes9x-${SNES9X_VERSION}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/snes9x/
COMMENT=	Libretro core based on the snes9x Super Nintendo emulator

BUILD_DIRS=	libretro

LIBRETRO_CORE=	snes9x

FORCE_CXX_STD=	c++11

.include "../../emulators/retroarch/core.mk"
.include "../../mk/bsd.pkg.mk"
