# $NetBSD: Makefile,v 1.9 2020/05/30 14:33:33 nia Exp $

DISTNAME=	libretro-gambatte-20200207
CATEGORIES=	emulators
GITHUB_PROJECT=	gambatte-libretro
GITHUB_TAG=	132f36e990dfc6effdafa6cf261373432464f9bf

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/gambatte/
COMMENT=	Libretro core based on the Gambatte Game Boy Color emulator
LICENSE=	gnu-gpl-v2

MAKE_FILE=	Makefile.libretro
USE_LANGUAGES=	c c++

LIBRETRO_CORE=	gambatte

.include "../../emulators/retroarch/core.mk"

CFLAGS.SunOS+=	-DBSD_COMP

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,-version-script=libgambatte/libretro/link.T

.include "../../mk/bsd.pkg.mk"
