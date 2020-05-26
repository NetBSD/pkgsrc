# $NetBSD: Makefile,v 1.5 2020/05/26 09:45:12 nia Exp $

DISTNAME=	libretro-nxengine-20181126
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_PROJECT=	nxengine-libretro
GITHUB_TAG=	0fd3d36eeb6339eb3c1cc185b0b6bd589331b1a9

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/nxengine/
COMMENT=	Libretro core based on the NXEngine game engine for Cave Story
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

OPSYSVARS+=	SOEXT
SOEXT.Darwin=	dylib
SOEXT.*=	so
PLIST_SUBST+=	SOEXT=${SOEXT}

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} == "big"
CFLAGS+=	-DMSB_FIRST
.endif

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=nxengine/libretro/link.T
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,-no-undefined

# nxengine/graphics/font.cpp: In function 'bool font_init()':
# nxengine/graphics/font.cpp:69:26: error: array subscript has type 'char' [-Werror=char-subscripts]
#    if (whitefont.letters[c]->h > fontheight)
# Maybe fix this later.
BUILDLINK_TRANSFORM+=	rm:-Werror=char-subscripts

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/nxengine_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/nxengine_libretro.so

.include "../../mk/bsd.pkg.mk"
