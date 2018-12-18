# $NetBSD: Makefile,v 1.1 2018/12/18 15:50:48 nia Exp $

.include "../../emulators/libretro-beetle-psx/Makefile.common"

PKGNAME=	libretro-beetle-psx-hw-${VERSION}

MAINTAINER=	nia@NetBSD.org
COMMENT=	Libretro core based on the Mednafen PlayStation emulator (OpenGL)

MAKE_FLAGS+=	HAVE_OPENGL=1

do-install:
	${INSTALL_LIB} ${WRKSRC}/mednafen_psx_hw_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/mednafen_psx_hw_libretro.so

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
