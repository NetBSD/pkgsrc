# $NetBSD: Makefile,v 1.9 2025/01/21 11:00:13 nia Exp $

DISTNAME=	libretro-genesis-plus-gx-20220901
CATEGORIES=	emulators
GITHUB_PROJECT=	Genesis-Plus-GX
GITHUB_TAG=	aea7b9d5475ec02427fbb00a9093cae74b87ff8a

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/genesis_plus_gx/
COMMENT=	Libretro core based on the Genesis Plus Sega 8/16 bit emulator
LICENSE=	mame-license

LDFLAGS+=	-lz

LIBRETRO_CORE=	genesis_plus_gx

.include "../../emulators/retroarch/core.mk"

MAKE_FILE=	Makefile.libretro

MAKE_FLAGS+=	SHARED_LIBVORBIS=1

.if ${MACHINE_ENDIAN} == "big"
MAKE_FLAGS+=	ENDIANNESS_DEFINES="-DBYTE_ORDER=BIG_ENDIAN -DCPU_IS_BIG_ENDIAN=1 -DWORDS_BIGENDIAN=1"
.endif

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=./libretro/link.T

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
