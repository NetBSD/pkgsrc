# $NetBSD: Makefile,v 1.9 2026/09/21 07:47:21 wiz Exp $

.include "../../emulators/sameboy/Makefile.common"

PKGNAME=	libretro-${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/sameboy/
COMMENT=	Libretro core based on the SameBoy Game Boy/Game Boy Color emulator

BUILD_TARGET=	libretro

LIBRETRO_CORE=	sameboy
MAKE_JOBS_SAFE=	no

.include "../../emulators/retroarch/core.mk"
.include "../../mk/bsd.pkg.mk"
