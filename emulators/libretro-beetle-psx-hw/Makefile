# $NetBSD: Makefile,v 1.4 2020/06/01 19:16:16 nia Exp $

LIBRETRO_CORE=	mednafen_psx_hw

.include "../../emulators/libretro-beetle-psx/Makefile.common"

PKGNAME=	libretro-beetle-psx-hw-${VERSION}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/beetle_psx_hw/
COMMENT=	Libretro core based on the Mednafen PlayStation emulator (OpenGL)

MAKE_FLAGS+=	HAVE_OPENGL=1

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
