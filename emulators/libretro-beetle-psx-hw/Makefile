# $NetBSD: Makefile,v 1.7 2025/02/12 06:44:44 ryoon Exp $

LIBRETRO_CORE=	mednafen_psx_hw

PKGREVISION= 2
.include "../../emulators/libretro-beetle-psx/Makefile.common"

PKGNAME=	libretro-beetle-psx-hw-${VERSION}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/beetle_psx_hw/
COMMENT=	Libretro core based on the Mednafen PlayStation emulator (OpenGL)

MAKE_FLAGS+=	HAVE_OPENGL=1

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
