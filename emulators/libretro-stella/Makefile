# $NetBSD: Makefile,v 1.8 2021/02/14 11:43:34 wiz Exp $

.include "../../emulators/stella/Makefile.common"
GITHUB_PROJECT=	stella

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
