# $NetBSD: Makefile,v 1.8 2026/11/25 14:42:05 wiz Exp $

LIBRETRO_CORE=	mednafen_psx_hw

PKGREVISION= 2
.include "../../emulators/libretro-beetle-psx/Makefile.common"

PKGNAME=	libretro-beetle-psx-hw-${VERSION}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/beetle_psx_hw/
COMMENT=	Libretro core based on the Mednafen PlayStation emulator (OpenGL)

MAKE_FLAGS+=	HAVE_OPENGL=1

.include "../../mk/mesa.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
