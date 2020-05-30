# $NetBSD: Makefile,v 1.8 2020/05/30 15:12:46 nia Exp $

.include "../../emulators/nestopia/Makefile.common"

PKGNAME=	libretro-${DISTNAME}

MAINTAINER=	snj@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/nestopia_ue/
COMMENT=	Libretro core based on the Nestopia UE emulator

BUILD_DIRS=	libretro

LIBRETRO_CORE=	nestopia

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,-version-script=link.T

.include "../../emulators/retroarch/core.mk"
.include "../../mk/bsd.pkg.mk"
