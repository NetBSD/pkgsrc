# $NetBSD: Makefile,v 1.2 2018/10/02 21:09:28 nia Exp $

DISTNAME=	libretro-beetle-ngp-20180720
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_PROJECT=	beetle-ngp-libretro
GITHUB_TAG=	69293c940ca27008ab2a1e37cc3077c677b36d1e

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/beetle_neopop/
COMMENT=	Libretro core based on the Mednafen Neo Geo Pocket emulator
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++
MAKE_FLAGS+=	GIT_VERSION="-pkgsrc"

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} == "big"
CFLAGS+=	-DMSB_FIRST
.endif

BUILD_MAKE_FLAGS+=	GIT_VERSION="-pkgsrc"

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=link.T
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--no-undefined

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/mednafen_ngp_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/mednafen_ngp_libretro.so

.include "../../mk/bsd.pkg.mk"
