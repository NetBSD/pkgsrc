# $NetBSD: Makefile,v 1.4 2020/05/31 17:49:49 nia Exp $

NP2KAI_REV=	18
DISTNAME=	libretro-np2kai-0.86.${NP2KAI_REV}
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=AZO234/}
GITHUB_PROJECT=	NP2kai
GITHUB_TAG=	rev.${NP2KAI_REV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/neko_project_ii_kai/
COMMENT=	Libretro core based on the Neko Project II PC-9801 emulator
LICENSE=	mit

BUILD_DIRS=	sdl2
MAKE_FILE=	Makefile.libretro

LIBRETRO_CORE=	np2kai

USE_LANGUAGES=	c c++

.include "../../mk/bsd.prefs.mk"

# The networking code currently uses non-portable Linux-specific calls.
.if ${OPSYS} != "Linux"
MAKE_FLAGS=	SUPPORT_NET=0
.endif

.include "../../emulators/retroarch/core.mk"
.include "../../mk/bsd.pkg.mk"
