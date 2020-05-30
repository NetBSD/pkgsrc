# $NetBSD: Makefile,v 1.6 2020/05/30 15:20:12 nia Exp $

.include "../../emulators/snes9x/Makefile.common"

PKGNAME=	libretro-snes9x-${SNES9X_VERSION}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/snes9x/
COMMENT=	Libretro core based on the snes9x Super Nintendo emulator

BUILD_DIRS=	libretro

LIBRETRO_CORE=	snes9x

.include "../../emulators/retroarch/core.mk"
.include "../../mk/bsd.pkg.mk"
