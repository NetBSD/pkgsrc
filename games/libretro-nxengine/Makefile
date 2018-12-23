# $NetBSD: Makefile,v 1.1 2018/12/23 15:05:52 nia Exp $

DISTNAME=	libretro-nxengine-20181126
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_PROJECT=	nxengine-libretro
GITHUB_TAG=	0fd3d36eeb6339eb3c1cc185b0b6bd589331b1a9

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/nxengine/
COMMENT=	Libretro core based on the NXEngine game engine for Cave Story
LICENSE=	gnu-gpl-v3

EXTRACT_USING=	bsdtar
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} == "big"
CFLAGS+=	-DMSB_FIRST
.endif

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,-version-script=build/link.T
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,-no-undefined

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/nxengine_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/nxengine_libretro.so

.include "../../mk/bsd.pkg.mk"
