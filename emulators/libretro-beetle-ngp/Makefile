# $NetBSD: Makefile,v 1.7 2020/06/02 12:24:09 nia Exp $

DISTNAME=	libretro-beetle-ngp-20200518
CATEGORIES=	emulators
GITHUB_PROJECT=	beetle-ngp-libretro
GITHUB_TAG=	3d31f4ad9f8d8367ccf492f04640c8ca172ef81d

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/beetle_neopop/
COMMENT=	Libretro core based on the Mednafen Neo Geo Pocket emulator
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++03

LIBRETRO_CORE=	mednafen_ngp

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=link.T 

.include "../../emulators/retroarch/core.mk"
.include "../../mk/bsd.pkg.mk"
