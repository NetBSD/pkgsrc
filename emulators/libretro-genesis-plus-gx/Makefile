# $NetBSD: Makefile,v 1.3 2018/10/02 21:09:29 nia Exp $

DISTNAME=	libretro-genesis-plus-gx-20180607
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_PROJECT=	Genesis-Plus-GX
GITHUB_TAG=	5ae12e75a08cf48ca1d350520998bf18db846381

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/genesis_plus_gx/
COMMENT=	Libretro core based on the Genesis Plus Sega 8/16 bit emulator
LICENSE=	mame-license

EXTRACT_USING=	bsdtar
USE_TOOLS+=	gmake

MAKE_FILE=	Makefile.libretro

MAKE_FLAGS+=	GIT_VERSION="-pkgsrc"
MAKE_FLAGS+=	SHARED_LIBVORBIS=1

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} == "big"
MAKE_FLAGS+=	ENDIANNESS_DEFINES="-DBYTE_ORDER=BIG_ENDIAN -DCPU_IS_BIG_ENDIAN=1 -DWORDS_BIGENDIAN=1"
.endif

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=./libretro/link.T
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--no-undefined

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/genesis_plus_gx_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/genesis_plus_gx_libretro.so

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
