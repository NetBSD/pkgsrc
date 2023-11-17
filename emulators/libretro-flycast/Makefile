# $NetBSD: Makefile,v 1.10 2023/11/17 09:27:51 nia Exp $

.include "../../emulators/flycast/Makefile.common"

PKGNAME=	libretro-${DISTNAME}

MAINTAINER=	nia@NetBSD.org
COMMENT=	Libretro core based on the Flycast Sega Dreamcast emulator

CMAKE_ARGS+=	-DLIBRETRO=ON
CMAKE_ARGS+=	-DCMAKE_INSTALL_BINDIR=lib/libretro

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
