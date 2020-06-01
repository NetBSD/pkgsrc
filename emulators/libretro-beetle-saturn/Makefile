# $NetBSD: Makefile,v 1.7 2020/06/01 19:36:32 nia Exp $

DISTNAME=	libretro-beetle-saturn-20200526
CATEGORIES=	emulators
GITHUB_PROJECT=	beetle-saturn-libretro
GITHUB_TAG=	7ba4ff3aed62a60e99e0758a92dbb1924c63d0fa

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/beetle_saturn/
COMMENT=	Libretro core based on the Mednafen Sega Saturn emulator
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++

LIBRETRO_CORE=	mednafen_saturn

LDFLAGS+=	-lFLAC -lz

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
MAKE_FLAGS+=	HAVE_CDROM=0
.endif

# "experimental, x86_64 only" - https://mednafen.github.io/
# Not built by upstream's buildbot for i386, ARM, or PowerPC.
ONLY_FOR_PLATFORM=	*-*-x86_64

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=link.T

.include "../../emulators/retroarch/core.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
