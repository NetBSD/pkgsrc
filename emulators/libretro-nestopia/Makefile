# $NetBSD: Makefile,v 1.9 2020/06/25 12:38:52 nia Exp $

.include "../../emulators/nestopia/Makefile.common"

PKGNAME=	libretro-${DISTNAME}

MAINTAINER=	snj@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/nestopia_ue/
COMMENT=	Libretro core based on the Nestopia UE emulator

BUILD_DIRS=	libretro

LIBRETRO_CORE=	nestopia

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,-version-script=link.T
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,-no-undefined

.include "../../emulators/retroarch/core.mk"
.include "../../mk/bsd.pkg.mk"
