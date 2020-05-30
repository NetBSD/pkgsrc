# $NetBSD: Makefile,v 1.7 2020/05/30 15:12:46 nia Exp $

.include "../../emulators/sameboy/Makefile.common"

PKGNAME=	libretro-${DISTNAME}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/sameboy/
COMMENT=	Libretro core based on the SameBoy Game Boy/Game Boy Color emulator

BUILD_DIRS=	libretro

LIBRETRO_CORE=	sameboy

.include "../../emulators/retroarch/core.mk"
.include "../../mk/bsd.pkg.mk"
