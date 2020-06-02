# $NetBSD: Makefile,v 1.1 2020/06/02 13:25:45 nia Exp $

LIBRETRO_CORE=	gearboy

.include "../../emulators/gearboy/Makefile.common"
.include "../../emulators/retroarch/core.mk"

PKGNAME=	libretro-${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/gearboy/
COMMENT=	Libretro core based on the Gearboy Game Boy emlator
LICENSE=	gnu-gpl-v3

BUILD_DIRS=	platforms/libretro

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,-version-script=./link.T

.include "../../mk/bsd.pkg.mk"
