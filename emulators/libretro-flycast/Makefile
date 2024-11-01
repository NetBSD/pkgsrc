# $NetBSD: Makefile,v 1.15 2024/11/01 12:52:27 wiz Exp $

PKGREVISION= 4
.include "../../emulators/flycast/Makefile.common"

PKGNAME=	libretro-${DISTNAME}

MAINTAINER=	nia@NetBSD.org
COMMENT=	Libretro core based on the Flycast Sega Dreamcast emulator

CMAKE_CONFIGURE_ARGS+=	-DLIBRETRO=ON
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_INSTALL_BINDIR=lib/libretro

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
