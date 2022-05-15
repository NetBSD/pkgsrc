# $NetBSD: Makefile,v 1.9 2022/05/15 18:36:18 nia Exp $

.include "../../emulators/stella/Makefile.common"

PKGNAME=	libretro-${DISTNAME:S/-src//1}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/stella/
COMMENT=	Libretro core based on the Stella Atari 2600 (VCS) emulator

BUILD_DIRS=	src/libretro

LIBRETRO_CORE=	stella

# Should not be combined with -fPIC
BUILDLINK_TRANSFORM+=	rm:-static-libgcc
BUILDLINK_TRANSFORM+=	rm:-static-libstdc++

.include "../../emulators/retroarch/core.mk"
.include "../../mk/bsd.pkg.mk"
