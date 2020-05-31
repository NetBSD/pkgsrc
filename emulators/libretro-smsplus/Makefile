# $NetBSD: Makefile,v 1.1 2020/05/31 17:01:08 nia Exp $

DISTNAME=	libretro-smsplus-20200425
CATEGORIES=	emulators
GITHUB_PROJECT=	smsplus-gx
GITHUB_TAG=	72b9bdccd6e5758ac17efd88b9bece94ec137e80

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/smsplus/
COMMENT=	Libretro core based on the SMS Plus Master System / Game Gear emulator
LICENSE=	gnu-gpl-v2

MAKE_FILE=	Makefile.libretro
LIBRETRO_CORE=	smsplus

MAKE_FLAGS+=	SOUND_ENGINE=crabemu_sn76489
MAKE_FLAGS+=	Z80_CORE=eighty

BUILDLINK_TRANSFORM+=	rm:-Wl,--version-script=link.T

.include "../../emulators/retroarch/core.mk"
.include "../../mk/bsd.pkg.mk"
