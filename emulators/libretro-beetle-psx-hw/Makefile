# $NetBSD: Makefile,v 1.5 2022/09/11 12:51:32 wiz Exp $

LIBRETRO_CORE=	mednafen_psx_hw

PKGREVISION= 1
.include "../../emulators/libretro-beetle-psx/Makefile.common"

PKGNAME=	libretro-beetle-psx-hw-${VERSION}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/beetle_psx_hw/
COMMENT=	Libretro core based on the Mednafen PlayStation emulator (OpenGL)

MAKE_FLAGS+=	HAVE_OPENGL=1

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
