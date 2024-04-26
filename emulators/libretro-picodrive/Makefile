# $NetBSD: Makefile,v 1.13 2024/04/26 09:04:31 nia Exp $

DISTNAME=	libretro-picodrive-20200527
PKGREVISION=	2
CATEGORIES=	emulators
GITHUB_PROJECT=	picodrive
GITHUB_TAG=	b8fb8f285317632f42ecbbd36cf4fe18ea9189f1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/picodrive/
COMMENT=	Libretro core based on the Picodrive MegaDrive/MegaCD/32X emulator
LICENSE=	mame-license

MAKE_FILE=	Makefile.libretro

LIBRETRO_CORE=	picodrive

.include "../../emulators/picodrive/Makefile.common"
.include "../../emulators/retroarch/core.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
