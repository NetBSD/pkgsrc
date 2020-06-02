# $NetBSD: Makefile,v 1.5 2020/06/02 12:24:10 nia Exp $

DISTNAME=	libretro-snes9x2010-20200518
CATEGORIES=	emulators
GITHUB_PROJECT=	snes9x2010
GITHUB_TAG=	187e2b58fc09dfeb9fdb5a95bc26786219a111cf

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/snes9x_2010/
COMMENT=	Libretro core based on the snes9x Super Nintendo emulator
LICENSE=	snes9x-license

MAKE_FILE=	Makefile.libretro

LIBRETRO_CORE=	snes9x2010

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=libretro/link.T

.include "../../emulators/retroarch/core.mk"
.include "../../mk/bsd.pkg.mk"
