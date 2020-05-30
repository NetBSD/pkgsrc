# $NetBSD: Makefile,v 1.5 2020/05/30 15:04:10 nia Exp $

DISTNAME=	libretro-genesis-plus-gx-20200208
CATEGORIES=	emulators
GITHUB_PROJECT=	Genesis-Plus-GX
GITHUB_TAG=	50551066f71f8a5ea782ea3747891fd6d24ebe67

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/genesis_plus_gx/
COMMENT=	Libretro core based on the Genesis Plus Sega 8/16 bit emulator
LICENSE=	mame-license

LIBRETRO_CORE=	genesis_plus_gx

.include "../../emulators/retroarch/core.mk"

MAKE_FILE=	Makefile.libretro

MAKE_FLAGS+=	SHARED_LIBVORBIS=1

.if ${MACHINE_ENDIAN} == "big"
MAKE_FLAGS+=	ENDIANNESS_DEFINES="-DBYTE_ORDER=BIG_ENDIAN -DCPU_IS_BIG_ENDIAN=1 -DWORDS_BIGENDIAN=1"
.endif

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=./libretro/link.T

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
