# $NetBSD: Makefile,v 1.6 2020/05/31 16:22:35 nia Exp $

DISTNAME=	libretro-nxengine-20200109
CATEGORIES=	games
GITHUB_PROJECT=	nxengine-libretro
GITHUB_TAG=	f39250e54f20c616dd4403cb8d4cab14032530b5

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/nxengine/
COMMENT=	Libretro core based on the NXEngine game engine for Cave Story
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++
LIBRETRO_CORE=	nxengine

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} != "x86_64"
MAKE_FLAGS+=	SINGLE_PRECISION_FLOATS=1
MAKE_FLAGS+=	MIN_AUDIO_PROCESSING_PER_FRAME=1
.endif

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=nxengine/libretro/link.T

.include "../../emulators/retroarch/core.mk"
.include "../../mk/bsd.pkg.mk"
