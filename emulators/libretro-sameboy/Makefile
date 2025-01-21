# $NetBSD: Makefile,v 1.8 2025/01/21 11:00:13 nia Exp $

.include "../../emulators/sameboy/Makefile.common"

PKGNAME=	libretro-${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/sameboy/
COMMENT=	Libretro core based on the SameBoy Game Boy/Game Boy Color emulator

BUILD_DIRS=	libretro

LIBRETRO_CORE=	sameboy

.include "../../emulators/retroarch/core.mk"
.include "../../mk/bsd.pkg.mk"
