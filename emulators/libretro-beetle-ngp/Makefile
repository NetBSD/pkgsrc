# $NetBSD: Makefile,v 1.4 2019/02/25 21:37:41 nia Exp $

DISTNAME=	libretro-beetle-ngp-20190203
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_PROJECT=	beetle-ngp-libretro
GITHUB_TAG=	78eb883d0e9efbb8a66be20f3938f1616453cea6

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/beetle_neopop/
COMMENT=	Libretro core based on the Mednafen Neo Geo Pocket emulator
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++03
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
