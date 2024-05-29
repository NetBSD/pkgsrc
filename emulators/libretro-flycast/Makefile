# $NetBSD: Makefile,v 1.12 2024/05/29 16:32:26 adam Exp $

PKGREVISION= 2
.include "../../emulators/flycast/Makefile.common"

PKGNAME=	libretro-${DISTNAME}

MAINTAINER=	nia@NetBSD.org
COMMENT=	Libretro core based on the Flycast Sega Dreamcast emulator

CMAKE_ARGS+=	-DLIBRETRO=ON
CMAKE_ARGS+=	-DCMAKE_INSTALL_BINDIR=lib/libretro

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
